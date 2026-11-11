#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN=5e5+5;

LL n,m,a[MAXN],s[MAXN],ans;
bool f_spab=true;
//int dp[MAXN][MAXN];

LL solve_spab()
{
    LL d=a[2]-a[1];
    return (-1+sqrt(1+8.0*m/d))/2ll+1;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    LL dic=a[2]-a[1];
    s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(dic!=a[i]-a[i-1])f_spab=false;
    }
    if(f_spab)
    {
        cout<<solve_spab();
        return 0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            if(a[r]*len-(s[r]-s[l-1])<=m)
            {
                ans=len;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
