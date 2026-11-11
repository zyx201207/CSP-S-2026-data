#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],b[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int cnt=0,p=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            b[i]=a[i+1];
            a[i+1]=a[i];
            a[i]=a[i+1];
        }
    }
    for(int i=1;i<=n-1;i++){
        if(cnt<m){
            if(a[i]<=a[i+1]){
                p++;
                if(a[i]!=a[i+1]){
                    cnt+=p*(a[i+1]-a[i]);
                }
            }
            if(cnt==m){
                p++;
            }
            if(cnt>m){
                p--;
            }
        }
        if(a[i]==a[i+1]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
