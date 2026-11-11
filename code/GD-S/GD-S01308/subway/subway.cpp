#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll a[N] , c , n , m , d , p , b1[N] , c1[N] , b2[N] , c2[N] , cnt[N];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	cin >> c >> n >> m >> d >> p;
	if(n <= 2){
		for(int i = 1 ; i <= m ; i ++){
			cin >> a[i];
		}
		int t1;
		cin >> t1;
		for(int i = 1 ; i <= t1 ; i ++){
			cin >> b1[i] >> c1[i];
			cnt[b1[i]] ++;
		}
		int k = 0;
		int t2;
		cin >> t2;
		for(int i = 1 ; i <= t2 ; i ++){
			cin >> b2[i] >> c2[i];
			if(cnt[b2[i]] != 0){
				k = b2[i];
			}
		}
		for(int i = 1 ; i <= p ; i ++){
			int x , y;
			cin >> x >> y;
			if((cnt[x] != 0 && cnt[y] == 0) || (cnt[x] == 0 && cnt[y] != 0)){
				cout << a[x] + c1[b1[x]] + c1[b1[k]] + c2[b2[k]] + c2[b2[y]] + a[y] << endl;
			}else{
				cout << a[x] + c1[b1[x]] + c2[b2[y]] + a[y] << endl;
			}
		}
	}
	return 0;
}
