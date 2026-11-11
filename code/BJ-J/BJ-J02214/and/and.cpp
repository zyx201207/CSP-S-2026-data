#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool c[200005];
int amax=INT_MIN;
int ans;
int anss;
int ansmax=INT_MIN;
bool con;
int main(){
    //:
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        amax=max(amax,a[i]);
    }
    if(m==n){
        con=1;
        ans=a[1];
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
    }else if(m==1){
        cout<<amax;
        return 0;
    }else if(n<=20){
        for(int i=1;i<=n;i++){
            anss=a[i];
            for(int j=1;j<=m;j++){
                for(int k=i+1;k<=n;k++){
                    if(c[k]==0){
                        c[k]=1;
                        anss=anss&a[k];
                    }
                }
            }
            ansmax=max(ansmax,anss);
            for(int i=1;i<=n;i++){
                c[i]=0;
            }
        }
    }else{
        cout<<amax;
        return 0;
    }
    if(con==1){
        cout<<ans;
    }else{
        cout<<ansmax;
    }
return 0;
}
