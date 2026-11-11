#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define endl "\n"
#define ll long long
ll n,m;
ll a[MAXN];
ll ans=0;
ll enge=0;
void acce(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    acce();
    cin >> n >> m;
    for (int i=1;i<=n;i++){cin >> a[i];}
    sort(a+1,a+n+1);
    ans=1,enge=0;
    ll head=1;
    for (ll i=2;i<=n;i++)
    {
        ll k=a[i]-a[i-1];
        enge+=(i-head)*k;
        while (enge>m && head<=i)
         {
            enge-=a[i]-a[head];
            head++;
            ans=max(i-head+1,ans);
        }
        ans=max(i-head+1,ans);
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
