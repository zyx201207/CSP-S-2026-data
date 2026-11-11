#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5;
ll n;
ll m;
ll a[N],dif[N];
ll ji = 0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(ll i=1;i<=n-1;i++) dif[i] = a[i + 1] - a[i];
    for(ll i=1;i<=n;i++)
    {
        ji += dif[i] * i;
        if(ji > m)
        {
            cout << i << '\n';
            return 0;
        }
    }
    if(ji == 0)
    {
        cout << 1 << " ";
        return 0;
    }
    cout << n << '\n';
    return 0;
}
