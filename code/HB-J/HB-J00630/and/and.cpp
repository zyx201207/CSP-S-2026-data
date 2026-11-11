#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1,cmp);
    ll cnt=a[1];
    for(int i=2;i<=m;i++)
    {
        cnt&=a[i];
    }
    cout << cnt;
    return 0;
}
