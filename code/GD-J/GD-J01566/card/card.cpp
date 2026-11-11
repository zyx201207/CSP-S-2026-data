#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , ans[N];
bool f[N];
stack<int> now;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];/*
	for(int i = 1; i <= n; i++){
		memset(f , 0 , sizeof(f));
		while(!now.empty()) now.pop();
		for(int j = i; j <= n; j++){
			if(f[a[j]] == 0){
				f[a[j]] = 1;
				now.push(a[j]);
			}else{
				while(now.top() != a[j] && !now.empty()) now.pop();
			}
		}
		memset(f , 0 , sizeof(f));
		while(!now.empty()){
			int t = now.top();
			if(!f[t]){
				f[t] = 1;
				ans[t]++;
				//cout << t << " ";
			}
			now.pop();
		}
		//cout << "\n";
	}*/
	for(int i = 1; i <= n; i++){
		ans[a[i]]++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
