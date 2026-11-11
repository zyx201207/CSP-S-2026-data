#include<bits/stdc++.h>
using namespace std;
int a[500010],dp[300010],b[300010];
bool vis[300010],c[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--) {
        for(int j=i;j<=n;j++) {
            c[j]=1;
        }
        for(int j=i;j<=n;j++) {
            dp[a[j]]++;
            if(vis[a[j]]) {
                for(int k=b[a[j]];k<j;k++) {
                    dp[a[k]]-=(1*c[j]);
                    vis[a[k]]=0;
                }
            }
            c[b[a[j]]]=0;
            vis[a[j]]=1;
            b[a[j]]=j;
        }
    }
    for(int i=1;i<=m;i++) {
        cout<<dp[i]<<" ";
    }
    return 0;
}
