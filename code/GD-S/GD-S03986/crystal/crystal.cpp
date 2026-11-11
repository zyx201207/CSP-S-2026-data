#include <bits/stdc++.h>
using namespace std;
long long a[5000005],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long l=-2e18,r=2e18;
	while (l <= r){
		long long d=(l+r)/2,k=m,cnt = 0;
		long long t = upper_bound(a+1,a+n+1,d)-a-1;
		for (int i = t;i >= 1;i --){
			if (d-a[i] <= k){
				k -= d-a[i];
				cnt ++;
			}
			else{
				k = 0;
				break;
			}
		}
		maxn = max(maxn,cnt);
		if (k==0)r=d-1;
		else l=d+1;
	}
	cout << maxn;
	return 0;
}
