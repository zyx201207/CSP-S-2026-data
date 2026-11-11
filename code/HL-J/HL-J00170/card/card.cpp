#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[300010];
bool vis[300010];
stack <int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!vis[a[j]])
            {
                s.push(a[j]);
                vis[a[j]]==true;
            }
            else
            {
                while(s.top()!=a[j])
                {
                    vis[s.top()]=false;
                    s.pop();

                }


            }

        }
        while(!s.empty())
        {
            sum[s.top()]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}
