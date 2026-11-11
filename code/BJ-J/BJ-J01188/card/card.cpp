#include<bits/stdc++.h>
using namespace std;
bool g[5005];
int n,m;
int cnt[5005];
vector <int> v;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    v.push_back(-1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);

    }
    for(int i=1;i<=n;i++)
    {
        stack<int> q;
        for(int j=i;j<=n;j++)
        {
            if(j==i)
            {
                q.push(v[j]);
                g[v[j]]=1;
            }
            else
            {
                if(g[v[j]])
                {
                    while(!q.empty()&&q.top()!=v[j])
                    {
                        g[q.top()]=0;
                        q.pop();
                    }
                    q.pop();
                    g[v[j]]=1;
                    q.push(v[j]);
                }
                else
                {
                    q.push(v[j]);
                    g[v[j]]=1;
                }
            }

        }
        if(!q.empty())
        {
            while(!q.empty())
            {
                cnt[q.top()]++;
                q.pop();
            }

        }
        for(int i=1;i<=m;i++)
        {
            g[i]=0;
        }

    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
