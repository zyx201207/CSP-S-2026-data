#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll cnt[N] , n , sum , t , c , d;
char b;
struct node{
	ll cnt , x;
	char y;
}a[N];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
    cin >> n;
    int flag = 0;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i].x >> a[i].y;
		cnt[a[i].x] ++;
		a[i].cnt = cnt[a[i].x];
		if(i == 1){
			c = a[i].x;
		}else if(i == n){
			d = a[i].x;
		}
		if(a[i].x != a[i - 1].x && i >= 2){
			flag = 1;
		}
	}
	if(flag == 0){
		cout << 0;
		return 0;
	}
	sort(cnt + 1 , cnt + 1 + n , greater<int>());	
	for(int i = 1 ; i <= n ; i ++){
		if(a[i].cnt == cnt[1]){
			t = a[i].x;
			b = a[i].y;
		}
	}
	if(c == t || d == t){
		for(int i = 1 ; i <= n ; i ++){
			if(a[i].y != b){
				sum += a[i].x;
			}
		}
		cout << sum;
	}
	return 0;
}
