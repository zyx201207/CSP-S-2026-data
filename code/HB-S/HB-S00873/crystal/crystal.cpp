#include<bits/stdc++.h>
using namespace std;
int n,m,qq;
int a[500005];
int c=INT_MIN,mb;
int bfs(int x,int nl,int gs)
{
    if(x>n)
    {
        return gs;
    }
    else
    {
        if(a[x]>mb || mb-a[x]+nl>m)
        {
            bfs(x+1,nl,gs);
        }
        else if(a[x]==mb)
        {
            bfs(x+1,nl,gs++);
        }
        else
        {
            bfs(x+1,nl+mb-a[x],gs++);
            bfs(x+1,nl,gs);
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        mb=a[i];
        qq=bfs(1,0,0);
        c=max(c,qq);
    }
    cout<<c+1;
    return 0;
}
