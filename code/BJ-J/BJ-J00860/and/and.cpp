#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005],n,m,ans;
void dfs(int st,int s,int x)
{
    if(st==m+1)
    {
        ans=max(ans,s);
        return;
    }
    for(int i=x;i<=n;i++) dfs(st+1,s&a[i],i+1);
}
map<ll,int>mp;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool fl=1;
    for(int i=0;i<=20;i++) mp[(ll)pow(2,i)-1]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        if(!mp[a[i]]) fl=0;
    }
    if(fl==1)
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1];
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++) dfs(2,a[i],i+1);
    cout<<ans;
    return 0;
}