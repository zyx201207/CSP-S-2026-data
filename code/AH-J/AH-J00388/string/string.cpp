#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
//注意先审题，再写，不要死磕，不要用复杂算法,记得释放注释检查

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll len=0,n;
    cin >> n;
    vector<ll> a(n+1);
    vector<char> c(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> c[i];
        len+=a[i];
    }
    ll l=1,r=len,lp=1,rp=n,ans=0;
    while(l<r)
    {
        if(lp==rp)
        {
            break;
        }
        ll m=min(a[lp],a[rp]);
        if(c[lp]!=c[rp])ans+=m;
        l+=m,r-=m;
        a[lp]-=m,a[rp]-=m;
        if(a[lp]==0)lp++;
        if(a[rp]==0)rp--;
    }
    cout << ans;
    return 0;
}
