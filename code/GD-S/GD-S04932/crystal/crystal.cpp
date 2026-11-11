#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long ans1 = 1;
	long long ans2 = 1;
	long long om = m;
	for(int i = 1;i < n;i++){
		if(m-(a[i+1]-a[i]) >= 0){
			m = m-(a[i+1]-a[i]);
			ans1++;
		}
	}
	for(int i = n;i > 1;i--){
		if(om-(a[i]-a[i-1]) >= 0){
			om = om-(a[i]-a[i-1]);
			ans2++;
		}
	}
	cout << max(ans1,ans2);
	return 0;
}
