#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> v[1005];
bool f[1005];
void dfs(int step)
{
    if(step==k)
    {
        for(int i = 1;i<=n;i++)
        {
            int minn = 1e9;
            for(int j = 1;j<=n;j++)
            {
                if(f[j])
                {
                    minn = min(minn,abs())
                }
            }
        }
    }
    for(int i = 1;i<=n;i++)
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        for(int i = 1;i<=n;i++) v[i].clear;
        cin>>n>>k;
        for(int i = 1;i<=n;i++)
        {
            int u,v;
            v[u].push_back(v);
        }
        dfs(1);
    }
    return 0;
}
