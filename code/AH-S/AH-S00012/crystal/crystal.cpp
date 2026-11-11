#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5+5;
ll n,m,ans=1;
ll a[M];
bool same=true,gs=true;
bool cost(ll x,ll y)
{
    ll cst=0;
    for(int i=x ; i<y ; i++)
    {
        cst += a[y]-a[i];
        if(cst>m) return false;
    }
    return true;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int t0=clock();

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        if(i>1) if(a[i]!=a[i-1])same=false;
        if(i>3) if(a[i]-a[i-1]!=a[i-1]-a[i-2])gs=false;
    }
    if(same)
    {
        cout << n;
        return 0;
    }
    if(gs)
    {
        ll gc=a[3]-a[2],sums=0,i;
        for(i=1 ;  ; i++)
        {
            sums += (i-1)*gc;
            if(sums>m)
            {
                cout << i-1;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    sort(a+1,a+n+1);

    for(int i=1 ; i<=n ; i++)
    {
        ll l=i-1,r=n+1;
        while(l<r)
        {
            ll mid = l+(r-l)/2;
            if(cost(i,mid)) l=mid;
            else r=mid;
            if(l+1==r)break;
        }
        ans = max(ans,r-i);
    }
    cout << ans;

    //cout << "\ntimeused:" << clock()-t0 << "ms";
    cout << endl;
    return 0;
}
