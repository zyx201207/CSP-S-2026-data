#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
bool vis[500005];
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        stack<int>q;
        memset(vis,false,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            int k=a[j];
            if(!vis[k])
            {
                q.push(k);
                vis[k]=true;
            }
            else
            {
                while(!q.empty()&&q.top()!=k)
                {
                    vis[q.top()]=false;
                    q.pop();
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(vis[j])
            {
                ans[j]++;
            }
        }
    }
    for(int j=1;j<m;j++)
    {
        cout<<ans[j]<<' ';
    }
    cout<<ans[m]<<"\n";
    return 0;
}