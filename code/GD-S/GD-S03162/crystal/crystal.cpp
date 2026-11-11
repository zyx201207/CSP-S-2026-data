#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],m,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,now=1,ans=-1;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-now);
		while(sum>m)
		{
			sum-=(a[i]-a[now]);
			now++;
		}
		ans=max(ans,i-now+1);
	}
	cout << ans << endl;
	return 0;
} 
