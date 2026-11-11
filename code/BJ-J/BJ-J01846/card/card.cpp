#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],mp[M],ap[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        mp[i]=0;
        ans[i]=0;
    }
    for(int i=n;i>=1;i--)if(mp[a[i]]==0)mp[a[i]]=i;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)ap[j]=1;
        for(int j=i;j<=n;j++){
            for(int k=j;k<mp[a[j]];k++)ap[k]=0;
            j=mp[a[j]];
        }
        for(int j=i;j<=n;j++)if(ap[j]==1)ans[a[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
