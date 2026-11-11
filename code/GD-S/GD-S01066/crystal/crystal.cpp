#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 5000005
LL n,m;
LL a[N];
LL b[N];
LL i = 1,j = 1;
LL ans,sum,maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n-1;i++) b[i] = a[i+1] - a[i];
//	for(int i = 1;i < n;i++) cout << b[i] << " ";
//	cout << "\n\n\n";
	while(j < n){
		sum += b[j-1]*ans;
		ans++;
//		int k = 1;
//		cout << i << " " << j << " " << ans << " " << sum << "\n";
		while(i <= j && sum > m && j < n){
//			sum -= k * b[i++];
//			k++;
			sum -= (a[j] - a[i++]);
			ans--;
//			cout << "!!!" << i << " " << j << " " << a[i] << " " << a[i] << " " << ans << " " << sum << "\n";
		}
		maxn = max(maxn,ans);
		++j;
	}
	cout << maxn;
	return 0;
}
