//GZ-S00339 遵义市第四中学 周语函 
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans = -1,c,k = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(i == 2) c = a[2]-a[1];
		if(i > 1){
			int tmp = a[i]-a[i-1];
			if(c!=tmp){
				k = 1;
			}
		}
	}
	sort(a+1,a+n+1);
	if(k == 0){
		if(c > m){
			cout << 1;
			return 0;
		}
		long long sum = 0;
		for(int i = 1 ; i > 0 ; i++){
			sum += c*i;
			if(sum > m){
				cout << i;
				return 0;
			} 
		}
	}
	for(long long i = 1 ; i <= n ; i++){
		long long sum = 1,tmp = m;
		for(long long j = i-1 ; j > 0 ; j--){
			if(tmp - a[i] + a[j] >= 0){
				tmp -= (a[i]-a[j]);
				sum++;
			}else break;
		}
		ans = max(sum,ans);
	}
	cout << ans;
	return 0;
}
