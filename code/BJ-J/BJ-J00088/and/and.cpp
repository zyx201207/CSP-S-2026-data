#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[200009];
long long maxx=-1;
bool flag=false;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=maxx){
            maxx=a[i];
        }
    }
    if(m==1){
        cout<<maxx;
        flag=true;
    }
    else if(m==2){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                else{
                    if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
                }
            }
        }
        cout<<ans;
        flag=true;
    }
    else if((m==n)&&(flag==false)){
        long long sss=a[1];
        for(int i=2;i<=n;i++){
            sss=sss&a[i];
        }
        cout<<sss;
    }
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
