#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],lst,ans = 2e0+2e1+2e2+2e3+2e4+2e5+2e6+2e7+2e8+2e9+2e10+2e11+2e12+2e13+2e14+2e15+2e16+2e17+2e18+2e19+2e20+2e21+2e22+2e23+2e24+2e25+2e26+2e27+2e28+2e29+2e30;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= m;i++)
    {
        int maxn = -1e18;
        int newlst = lst;
        for (int j = lst+1;j <= n;j++)
        {
            if ((ans&a[j]) > maxn)
            {
                newlst = j;
                maxn = ans&a[j];
            }
        }
        lst = newlst;
        ans = maxn;
    }
    cout << ans;
    return 0;
}
