#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
ll n,m,Min,Max;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int l = 1;
	ll Min = 0,sum = 0,cnt = 0,ans = 0;
	for(int r=2;r<=n;r++)
	{
		sum += ((a[r] - a[r-1])*(cnt+1));
		cnt++;
		while(sum > m)
		{
			cnt--;
			sum -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans,cnt+1);
	}
	cout << ans;
	return 0;
} 
