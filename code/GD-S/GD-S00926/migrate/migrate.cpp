#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100005;
ll n , d , x[N] , s[N];
struct Node{
	int x , times;
}dp[N];
bool check(int ts , int now){
	if(x[now] - x[ts] <= d){
		return true;
	}
	return false;
}
bool check1(int ts , int now){
	if(dp[ts].x == dp[now].x){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c , T;
	cin >> c >> T;
	while(T--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
		}
		for(int st = 1 ; st <= n ; st++){
			for(int i = st - 1; i <= n ; i++){
				dp[i].x = 10000000;
				dp[i].times = 0;
				s[i] = 0;
			}
			dp[st].x = 0;
			dp[st].times = 1;
			s[st] = 1;
			for(int i = st + 1; i <= n ; i++){
				ll l = st , r = i - 1;
//				cout << l << " " << r << endl;
				ll tt = -1;
				while(l <= r){
					int mid = (l+r)/2;
//					cout << mid << " " << x[mid] << " " << i << " " << x[i] << endl;
					if(check(mid,i)){
						r = mid - 1;
						tt = mid;
					}
					else{
						l = mid + 1;
					}		
				}
//				cout << tt << " " << i << endl;
				if(tt == -1 ) break;
				l = tt , r = i - 1;
				ll tt2 = -1;
				while(l <= r){
					int mid = (l + r)/2;
					if(check1(mid,tt)){
						l = mid + 1;
						tt2 = mid;
					}else{
						r = mid - 1;
					}
				}
				dp[i].times = s[tt2] - s[tt - 1];
				dp[i].x = dp[tt].x + 1;
				s[i] = s[i - 1] + dp[i].times;
				if(dp[i].times == 2){
//					cout << tt2 << " " << tt << " "  << st<< " " << i << endl;
					ans++;
				}
			}
//			for(int j = st ; j <= n ; j++){
//				cout << dp[j].x << " " ;
//			}
//			cout << endl;
//			for(int j = st ; j <= n ; j++){
//				cout <<dp[j].times << " ";
//			}
//			cout << endl;
//			cout << endl;
		}
		cout << ans << endl;
	}
}/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/
/*0 1
4 9
11 20 21 22*/
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/
