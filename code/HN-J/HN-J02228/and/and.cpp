#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
int n,m;
ll a[N],maxn;
void dfs(int x,int cnt,ll sum,int f)
{
    if(cnt>m) return;
    if(x>n)
    {
        if(cnt==m) maxn=max(maxn,sum);
        return;
    }
    if(f==0) dfs(x+1,cnt+1,a[x],1);
    else dfs(x+1,cnt+1,a[x]&sum,f);
    dfs(x+1,cnt,sum,f);
}
void solve1()
{
    ll sum=a[1];
    for(int i=1;i<=n;i++)
    {
        sum&=a[i];
    }
    cout<<sum;
}
void solve4()
{
    dfs(1,0,0,0);
    cout<<maxn;
}
void solve2()
{
    sort(a+1,a+n+1);
    cout<<a[n];
}
void solve3()
{
    ll maxx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    cout<<maxx;
}
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(i-1!=a[i]) return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        solve4();
    }
    else if(m==n)
    {
        solve1();
    }
    else if(m==1)
    {
        solve2();
    }
    else if(m==2)
    {
        solve3();
    }
    else if(check())
    {
        cout<<0;
    }
    else
    {
        solve4();
    }
    return 0;
}
