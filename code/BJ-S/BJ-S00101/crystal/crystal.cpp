#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    LL n,m;
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    sort(a+1, a+n+1);
    LL p = 1,ans = 1,now = 1;
    LL sum = 0;
    for (int i = 2;i <= n;i++)
    {
        sum += now * (a[i]-a[i-1]);
        now++;
        while (sum > m)
            now--,sum -= (a[i]-a[p++]);
        ans = max(ans,now); 
    }
    cout << ans << "\n";
	return 0;
}