#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int f[m+1]={},a[n+1]={},t[n+1]={};
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        t[i]=x;
        if(f[x]){
            for(int j=f[x];j<i;j++){
                a[j]=f[x];
            }
        }
        f[x]=i;
    }
    long long ans[m+1]={};
    for(int i=1;i<=n;i++){
        ans[t[i]]+=(i-a[i]);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
