#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll a[N] , cnt[N];
deque <ll> d;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	ll n , m;
	cin >> n >> m;
	ll flag = 0;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if(a[i] < a[i - 1]){
			flag = 1;
		}
	}
	if(flag == 0){
		for(int i = 1 ; i <= n ; i ++){
			int j = i;
			while(j <= n){
				if(a[j] == a[j - 1] && j >= i + 1){
					d.pop_back();
					while(a[j] == a[j + 1]){
						j ++;
					}
					d.push_back(a[j]);
				}else{
					d.push_back(a[j]);
				}
				j ++;
			}
			while(!d.empty()){
				cnt[d.front()] ++;
				d.pop_front();
			}
		}
		for(int i = 1 ; i <= m ; i ++){
			cout << cnt[i] << " ";
		}
	}else{
		for(int i = 1 ; i <= n ; i ++){
			int j = i;
			while(j <= n){
				int c = 0;
				for(int k = i ; k < j ; k ++){
					if(a[k] == a[j]){
						c = k;
					}
				}
				if(c != 0){
					for(int k = j - 1 ; k >= c ; k --){
						if(d.empty()) break;
						d.pop_back();
					}
					d.push_back(a[j]);
				}else{
					d.push_back(a[j]);
				}
				j ++;
			}
			while(!d.empty()){
				cnt[d.front()] ++;
				d.pop_front();
			}
		}
		for(int i = 1 ; i <= m ; i ++){
			cout << cnt[i] << " ";
		}
	}	
	return 0;
}
