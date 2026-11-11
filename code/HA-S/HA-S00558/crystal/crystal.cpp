#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long sum[N];
int ans;
int solve(int x){//计算假设以当前数为基准最多能合成多少水晶
	 int l = 1, r = x;
	 long long now = a[x];
//	 cout<<"Now:"<<now<<endl;
	 int res = 0;
	 while(l <= r){
	 	int mid = (l + r) >> 1;
	 	long long check = 1ll * (x - mid + 1) * now - sum[x] + sum[mid - 1];
//	 	cout<<mid<<' '<<check<<' '<<"sum:"<<sum[x] - sum[mid - 1]<<' '<<l<<' '<<r<<endl;
	 	if(check <= m){//当前可以合成这么多 
	 		res = x - mid + 1;
	 		r = mid - 1;
	 	}
	 	else{
	 		l = mid + 1;
	 	}
	 }
	 return res;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = a[i] + sum[i - 1];
	}
//	for(int i = 1;i <= n;i++){
//		cout<<sum[i]<<' ';
//	}
//	cout<<endl;
	for(int i = n;i >= 1;i--){
		ans = max(solve(i), ans);
	}
	cout<<ans<<endl;
	//5 5
	//1 2 4 8 9
	return 0;
	//14:56 搞定 
}
