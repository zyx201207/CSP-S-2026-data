#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N];
int ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int I = 2 ; I <= n + 1 ; I++){
		bool mark[N] = {};
		stack <int> s;
		for(int i = I - 1 ; i <= n ; i++){
			if(mark[a[i]] == 0){
				s.push(a[i]);
				mark[a[i]] = 1;
			}else{
				while(s.top() != a[i]){
					int top = s.top();
					s.pop();
					mark[top] = 0;
				}
			}
		}
		for(int i = 1 ; i <= m ; i++){
			if(mark[i]){
				ans[i]++;
			}
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
