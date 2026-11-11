#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,ans;
long long a[N];
long long p(int a,int b)
{
    long long num=0,q=0;
    while(a>0&&b>0)
    {
        if(a%2==1&&b%2==1)num+=1*(int)pow(2,q);
        a/=2,b/=2;
        q++;
    }
    return num;
}
void dfs(int ind,long long sum,int cnt)
{
    if(cnt==m)
        ans=max(ans,sum);
    for(int i=ind+1;i<=n;i++)
    {
        if(cnt==0)dfs(i,a[i],cnt+1);
        else dfs(i,p(sum,a[i]),cnt+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<20||m==2)
    {
        dfs(0,0,0);
        cout<<ans;
    }
    if(m==1)
    {
        long long maxn=-1;
        for(int i=1;i<=n;i++)
            maxn=max(maxn,a[i]);
        cout<<maxn;
    }
    else if(m==n)
    {
        for(int i=1;i<=n;i++)
            ans=p(ans,a[i]);
    }
    else
    {
        dfs(0,0,0);
        cout<<ans;
    }
    return 0;
}
