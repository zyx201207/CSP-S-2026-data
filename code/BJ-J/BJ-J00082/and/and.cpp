#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=-1;
void dfs(int num,long long now,int limit)
{
    if(num==n&&limit>0)
        return;
    if(limit==0)
    {
        maxx=max(maxx,now);
        return;
    }
    for(int i=num+1;i<=n;i++)
    {
        dfs(i,now&a[i],limit-1);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,pow(2,21)-1,m);
    cout<<maxx;
    return 0;
}
