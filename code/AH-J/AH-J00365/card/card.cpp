#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long point[600000],e[400000];
bool use[400000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    stack<int> a;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        point[i]=x;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a.empty())
            {
                a.push(point[j]);
                use[point[j]]=true;
                continue;
            }
            if(use[point[j]])
            {
                while(a.top()!=point[j]&&!a.empty())
                {
                    use[a.top()]=false;
                    a.pop();
                }
            }
            else
            {
                a.push(point[j]);
                use[point[j]]=true;
            }

        }
        while(!a.empty())
        {
            use[a.top()]=false;
            e[a.top()]++;
            a.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<e[i]<<' ';
    }
    return 0;
}
