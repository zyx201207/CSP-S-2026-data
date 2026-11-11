#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long q[500005];
bool cmp(long long a,long long b){
	return a < b;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
	}
	sort(a+1 , a+n+1 , cmp);
	for(int i = 1 ; i <= n ; i ++) {
		q[i] = q[i - 1] + a[i];
//		cout << q[i] << " ";
	}
//	cout << "\n";
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++) {
		int l = 1;
		int r = i;
		int best = 0;
		while(l <= r) {
			int mid = (l + r) / 2;//数量 
			long long v = q[i] - q[i - mid];
//			cout << i << "至" << i - mid << ":" <<"长度："<<mid<<" "<< v << "\n"; 
			long long need = (a[i] * mid )- v;//补齐所需 
//			cout << "需要："<<q[i]*mid<<" "<< need << "\n"; 
			if(m >= need){
				best = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
//			cout << need << " ";
		}
//		for(int j = l ; j <= r ; j ++) {
//			long long v = q[i] - q[i - j];
//			long long need = q[i] * j - v;
//			if(m >= need) {
//				best = j;
//			} else{
//				break;
//			}
//			cout << v << " " << need << "\n";
//		}
//		cout<< "\n";
		ans = max(ans , best);
	}
	cout << ans;
	return 0;
}
//  5 5 1 2 4 8 9 
