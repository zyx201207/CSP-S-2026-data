#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,a[200005],maxn=-1145141918;
void dfs(long long num,long long z,long long y,long long s)
{
    if(y>=m)
    {
        maxn=max(maxn,z);
        return;
    }
    if(num>n)
    {
        return;
    }
    if(s==-1)
    {
        dfs(num+1,a[num],y+1,a[num]);
        dfs(num+1,z,y,-1);
    }
    else
    {
        dfs(num+1,z&a[num],y+1,a[num]);
        dfs(num+1,z,y,s);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,-1);
    cout<<maxn;
    return 0;
}

