#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll n,m,a[maxn],ans;
inline bool cmp(ll x,ll y){return x>y;}
inline void dfs(ll st,ll tm,ll res)
{
    if(tm==m)
    {
        ans=max(ans,res);
        return ;
    }
    for(int i=st;i<=n;i++) dfs(i+1,tm+1,res&a[i]);
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20)
    {
        dfs(1,0,1073741823);
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j) ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else
    {
        sort(a+1,a+1+n,cmp);
        ans=1073741823;
        for(int i=1;i<=m;i++) ans=ans&a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
