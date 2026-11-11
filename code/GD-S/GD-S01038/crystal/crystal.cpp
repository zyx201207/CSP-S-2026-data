#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	long long mid=(l+r)/2;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=a[mid]&&m>=a[mid]-a[i])
		{
			m-=a[mid]-a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
