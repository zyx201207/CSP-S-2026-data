#include <bits/stdc++.h>
using namespace std;
int a[500010];
bool f[500010];
int cnt[300010];
int last[300010];
bool sum[500010];
int s[500010];
int ans[500010];
int mx[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        ans[i]=1;
    }
    for(int i=1;i <= n;i++)
    {
        memset(last,0,sizeof(last));
        for(int j=i;j <= n;j++)
        {
            if(last[a[j]]==0)
            {
                last[a[j]]=j;
            }
            else if(last[a[j]]!=0)
            {
                sum[last[a[j]]+1]-=1;
                sum[j]+=1;
            }
        }
        for(int j=1;j <= n;j++)
        {
            if(sum[j]==0)
            {
                s[i]--;
            }
        }
    }
    for(int i=1;i <= n;i++)
    {
        ans[i]+=s[i];
    }
    for(int i=1;i <= n;i++)
    {
        mx[a[i]]=max(mx[a[i]],ans[i]);
    }
    for(int i=1;i <= m;i++)
    {
        printf("%d ",mx[i]);
    }
    return 0;
}