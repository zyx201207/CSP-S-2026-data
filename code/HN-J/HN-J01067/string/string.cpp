#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define mp make_pair
#define ls p << 1
#define rs p << 1 | 1
typedef long long ll;
const int N = 2e5 + 5;
int n;
ll L, ans, posl[N], posr[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		ll a;
		cin >> a >> c[i];
		posl[i] = L + 1;
		L += a;
		posr[i] = L;
	}
	ll l = 1, r = L, li = 1, ri = n;
	while(l <= r)
	{
		if(li == ri) break;
		if(c[li] != c[ri])
		{
			if(posr[li] - l + 1 > r - posl[ri] + 1)
			{
				l += r-posl[ri] + 1;
				ans += r-posl[ri]+1;
				ri--;
				r = posr[ri];
			}
			else if(posr[li] - l + 1 < r - posl[ri] + 1)
			{
				r -= posr[li]-l+1;
				ans += posr[li]-l+1;
				li++;
				l = posl[li];
			}
			else
			{
				ans += posr[li]-l+1;
				li++,ri--;
				l = posl[li];
				r = posr[ri];
			}
		}
		else
		{
			if(posr[li] - l + 1 > r - posl[ri] + 1)
			{
				l += r-posl[ri] + 1;
				ri--;
				r = posr[ri];
			}
			else if(posr[li] - l + 1 < r - posl[ri] + 1)
			{
				r -= posr[li]-l+1;
				li++;
				l = posl[li];
			}
			else
			{
				li++,ri--;
				l = posl[li];
				r = posr[ri];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
