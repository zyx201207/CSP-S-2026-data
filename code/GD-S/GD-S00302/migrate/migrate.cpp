#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int a[N];
int ans = 1e9;
int cnt = 1;
int n , m;
int sumcnt =0;
void dfs(int x , int goal , int step){
	if(x == goal){
		if(step == ans ){
			cnt++;
		}else if(ans > step){
			ans = step;
			cnt = 1;
		}
		return;
	}
	for(int i = x +1; i <= n ; i++){
		if(a[i] - a[x] <=  m){
			dfs(i , goal , step + 1);
		}
	}
}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , p;
	cin >> c >> p;
	while(p--){	
		sumcnt  =0;
		cin >> n >> m;
		for(int i = 1;i <=n ; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n ; i++){
			for(int j = 1; j < i ; j++){
				cnt = 1;
				ans = 1e9;
				dfs(j , i , 0);
				if(cnt == 2){
					sumcnt++;	
				}	
			}
		}
		cout<<sumcnt<<endl;
	}
	
	return 0;
} 
