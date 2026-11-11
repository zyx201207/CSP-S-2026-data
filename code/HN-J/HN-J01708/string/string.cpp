#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;
int n,a[N];
char c[N];
ll sum,ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i],sum += a[i];
	ll sum1 = 0;
	int l = 1,r = n;
	while(l < r)
	{
		if(c[l] != c[r])
		{
			if(a[l] > a[r])
			{
				if(sum / 2 - sum1 >= a[r]) sum1 += a[r],a[l] -= a[r],ans += a[r],r--;
				else {ans += sum / 2 - sum1;break;}
			}
			else if(a[r] > a[l])
			{
				if(sum / 2 - sum1 >= a[l]) sum1 += a[l],a[r] -= a[l],ans += a[l],l++;
				else {ans += sum / 2 - sum1;break;}
			}
			else
			{
				if(sum / 2 - sum1 >= a[l]) sum1 += a[l],r--,ans += a[l],l++;
				else {ans += sum / 2 - sum1;break;}
			}
		}
		else
		{
			if(a[l] >= a[r])
			{
				if(sum / 2 - sum1 >= a[r]) sum1 += a[r],a[l] -= a[r],r--;
				else break;
			}
			else
			{
				if(sum / 2 - sum1 >= a[l]) sum1 += a[l],a[r] -= a[l],l++;
				else break;
			}
		}
	}
	cout << ans;
	return 0;
}
