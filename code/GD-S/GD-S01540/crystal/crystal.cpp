#include<bits/stdc++.h>
using namespace std;
int ans;
long long n,m;
long long a[1000005];
int aa = 1,x = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2;i <= n;i++){
		if((a[i] - a[i-1]) * aa + x > m){
			ans = max(ans,aa);
			x += (a[i]- a[i - 1])*aa;
			while(aa > 0 && x > m){
				x -= a[i] - a[i - aa];
				aa--;
			}
			aa++;
		}
		else{
			x += (a[i] - a[i - 1] * aa);
			aa++;
		}
	}
	cout << ans;
	return 0;
}
