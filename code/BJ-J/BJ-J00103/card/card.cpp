#include<bits/stdc++.h>
using namespace std;
const int M=3e3+4;
const int N=5e5+4;
int cnt[M],sd[N];
bool vis[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sd[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        stack<int> stk;
        for(int j=i;j<=n;j++)
        {
            if(vis[sd[j]]==true)
            {
                while(stk.top()!=sd[j])
                {
                    vis[stk.top()]=false;
                    stk.pop();
                }
            }
            else
            {
                vis[sd[j]]=true;
                stk.push(sd[j]);
            }
        }
        while(!stk.empty())
        {
            cnt[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}