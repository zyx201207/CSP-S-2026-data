#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m ;
	for (long long i = 1; i <= n; i++){
		cin >> a[i] ;
	}
	sort(a+1,a+n+1);
	long long ans1 = 0;
	for (long long i = 1,j = 1; i <= n; i++){
		m -= (a[i] - a[i-1])*(i - j);
		ans1++;
		//cout << sum << endl;
		if(m >= 0){
			ans = max(ans1,ans);
		}else{
			while(m < 0&&j < i){
				m += a[i] - a[j];
				ans1--;
				j++;
			}
		}
	}
	cout << ans ;
	return 0;
}
