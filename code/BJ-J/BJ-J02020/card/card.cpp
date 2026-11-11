/*
    9:07 T1 finish
    9:51 woc wo quan ping tui bu chu qu le
    9:54 tui chu qu le
    10:00 T2 finish
    only feels like nothing could be better when I'm with you
    dancing all night wishing blah blah blah is a break through
    X X XXX
    XX X XXX
    di yi ci bi sai , hao nan
    bu xiang xue bian cheng le
    wei shen me xue le 6 nian lian CSP-J dou na bu liao yi deng jiang
    TAT
    nan shou

*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int vis[M],h[M];
int a[N];
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[n+1-i];
    while(n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[a[i]]==0)
            {
                s.push(a[i]);
                vis[a[i]]++;
            }
            else
            {
                while(s.top()!=a[i])
                {
                    vis[a[i]]=0;
                    s.pop();
                }
            }
        }
        while(s.size())
        {
            h[s.top()]++;
            vis[s.top()]=0;
            s.pop();
        }
        n--;
    }
    for(int i=1;i<=m;i++)cout <<h[i]<<" ";
    return 0;
}
