#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt[10],n,m,ans;
void dfs(int x,int num,int now)
{
    if(x==n+1)
    {
        if(num==m) ans=max(ans,now);
        return ;
    }
    dfs(x+1,num,now);
    dfs(x+1,num+1,now&a[x]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans<<'\n';
    }
    if(m==2)
    {
        int ans=0;
        for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
        cout<<ans<<'\n';
        return 0;
    }
    if(m==n-1)
    {
        int tmp1=a[1],tmp2=a[2];
        for(int i=2;i<n;i++) tmp1&=a[i];
        for(int i=3;i<=n;i++) tmp2&=a[i];
        cout<<max(tmp1,tmp2)<<'\n';
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<'\n';
        return 0;
    }
    int temp=0;
    for(int i=1;i<=n;i++) temp=max(temp,a[i]);
    if(temp<=4)
    {
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        if(cnt[4]>=m) cout<<"4\n";
        else if(cnt[3]>=m) cout<<"3\n";
        else if(cnt[3]+cnt[2]>=m) cout<<"2\n";
        else if(cnt[1]>=m) cout<<"1\n";
        else cout<<"0\n";
        return 0;
    }
    dfs(1,0,2147483647);
    cout<<ans<<'\n';
    return 0;
}
