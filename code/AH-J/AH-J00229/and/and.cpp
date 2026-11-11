#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    vector<ll>a(n);
    for(int i  = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int k = 35;k >=0;k--)
    {
        vector<ll>manzu;
        for(int i = 0;i < n;i++)
            if(a[i]&(1ll<<k))
            {
                manzu.push_back(a[i]);
            }
        if((ll)manzu.size()>=m)
        {
            a=manzu;
            n=manzu.size();
            ans+=(1ll<<k);
        }
    }
    cout << ans;
	return 0;
}
