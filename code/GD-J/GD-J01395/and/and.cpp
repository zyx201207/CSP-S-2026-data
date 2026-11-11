#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,pre[200005],suf[200005];
void dfs(int pos,int sum,int cnt)
{
    if(cnt>=m)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=pos;i<=n;i++) dfs(i+1,sum&a[i],cnt+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20)
    {
        int maxn=1<<n,sum,cnt=0;
        for(int i=0;i<maxn;i++)
        {
            sum=INT_MAX;
            cnt=0;
            for(int j=0;j<n;j++) if((i>>j)&1) sum&=a[j+1],cnt++;
            if(cnt==m) ans=max(ans,sum);
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        pre[1]=a[1];
        for(int i=2;i<=n;i++) pre[i]=pre[i-1]&a[i];
        suf[n]=a[n];
        for(int i=n-1;i>=1;i--) suf[i]=suf[i+1]&a[i];
        for(int i=1;i<=n;i++) ans=max(ans,pre[i-1]&suf[i+1]);
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    dfs(1,INT_MAX,0);
    cout<<ans;
    return 0;
}
