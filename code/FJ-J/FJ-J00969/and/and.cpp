#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N] , b[N] , mark[N];
int n , m , maxn = -1e9;
void f(int x , int last){
	if(x == m+1){
		int ans = 0 , cnt = m;
		for(int i = 1 ; i <= n ; i++){
			if(mark[a[i]] == 1 && cnt-1 >= 0){
				cnt--;
				if(cnt + 1 == m) ans = a[i];
				else ans = ans & a[i];
				//cout << a[i] << " ";
			}
		}
		//cout << ans;
		//cout << endl;
		maxn = max(maxn , ans);
		return ;
	}
	else{
		for(int i = last+1 ; i <= n ; i++){
			if(mark[a[i]] != 1){
				mark[a[i]] = 1;
				f(x+1 , i);
				mark[a[i]] = 0;
			}
		}
	}
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	f(1 , 0);
	cout << maxn;
	return 0;
} 
