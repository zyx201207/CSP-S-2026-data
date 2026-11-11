#include <stack>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

stack<int> s;
queue<int> a;
int n,m;
const int MAXN2=3e5+10;
bool vis[MAXN2];
int ans[MAXN2];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        a.push(tmp);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            a.push(a.front());
            a.pop();
        }

        for(int j=i;j<=n;j++)
        {
            if(!vis[a.front()])
            {
                s.push(a.front());
                vis[a.front()]=1;
            }
            else
            {
                while(s.top()!=a.front())
                {
                    vis[s.top()]=0;
                    s.pop();
                }
            }

            a.push(a.front());
            a.pop();
        }

        while(!s.empty())
        {
            vis[s.top()]=0;
            ans[s.top()]++;
            s.pop();
        }
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";

    return 0;
}
