#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
int vis[M],cnt[M];
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]])
            {
                for(int k=vis[a[j]];k<=j;k++)
                {
                    vis[a[k]]=0;
                }
            }
            vis[a[j]]=j;
        }
        for(int k=1;k<=m;k++)
            if(vis[k])
                cnt[k]++;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}

