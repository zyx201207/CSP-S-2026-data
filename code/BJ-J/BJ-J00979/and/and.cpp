#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
int l[200010],r[200010];
bool cmp(int u,int v)
{
    if(log2(u)!=log2(v))return log2(u)>log2(v);
    else return u>v;
}
void dfs(int step,int cnt,int sum)
{
    if(step>n||cnt>=m)
    {
        if(cnt==m&&sum!=2147483647)ans=max(ans,sum);
        return;
    }
    dfs(step+1,cnt+1,sum&a[step]);
    dfs(step+1,cnt,sum);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<=20)dfs(1,0,2147483647);
    else
    {
        if(m==1)
        {
            for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        }
        else if(m==2)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        else if(m==n)
        {
            ans=2147483647;
            for(int i=1;i<=n;i++)ans&=a[i];
        }
        else if(m==n-1)
        {
            l[0]=2147483647;
            r[n+1]=2147483647;
            for(int i=1;i<=n;i++)l[i]=l[i-1]&a[i];
            for(int i=n;i>=1;i--)r[i]=r[i+1]&a[i];
            for(int i=1;i<=n;i++)ans=max(ans,l[i-1]&r[i+1]);
        }
        else
        {
            ans=2147483647;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=m;i++)ans&=a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
