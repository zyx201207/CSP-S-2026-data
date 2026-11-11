#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
void dfs(int now,int i,int cnt)
{
    if(cnt==m)
    {
        if(ans<now)
            ans=now;
        return;
    }
    if(i>n)return;
    if(n-i+1<m-cnt)return;
    dfs(now&a[i],i+1,cnt+1);
    dfs(now,i+1,cnt);
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(INT_MAX,1,0);
    printf("%d\n",ans);
    return 0;
}