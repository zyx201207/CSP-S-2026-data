#include<bits/stdc++.h>

using namespace std;
stack<int>q;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],js[M];
bool vis[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=i;j<n;j++)
        {
            if(vis[a[j]])
            {
                while(!q.empty())
                {
                    if(q.top()==a[j]) break;
                    vis[q.top()]=0;
                    q.pop();
                }
            }
            else
            {
                q.push(a[j]);
                vis[a[j]]=1;
            }
        }
        while(!q.empty())
        {
            js[q.top()]++;
            q.pop();
        }
        /*for(int i=1;i<=m;i++)
        {
            cout<<js[i]<<' ';
        }
        cout<<'\n';*/
    }
    for(int i=1;i<=m;i++)
    {
        cout<<js[i]<<' ';
    }
    return 0;
}
