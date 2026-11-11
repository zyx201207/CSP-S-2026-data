#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 1;
const int inf = 0x3f3f3f3f;
int a[N];
bool vis[N];
int n , m;
vector<int> vec;
void dfs(int num , int sum , bool hqt[]){
	if(sum == m){
		vec.push_back(num);
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!hqt[i]){
			hqt[i] = true;
			dfs(num & a[i] , sum + 1 , hqt);
			hqt[i] = false;
		}	
	}
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	if(n == m){
		for(int i = 1 ; i < n ; i ++){
			a[i + 1] &= a[i];
		}	
		cout << a[n];
	}else if(m == 1){
		for(int i = 1 ; i < n ; i ++){
			a[i + 1] = max(a[i] , a[i + 1]);
		}
		cout << a[n];
	}else if(m == 2){
		int ans = -inf;
		for(int i = 1 ; i < n ; i ++){
			ans = max(ans , a[i] & a[i + 1]);
		}
		cout << ans;
	}else{
		memset(vis , 0 , sizeof(vis));
		for(int i = 1 ; i <= n ; i ++){
			vis[i] = true;
			dfs(a[i] , 1 , vis);
			vis[i] = false;
		}
		sort(vec.begin() , vec.end());
		cout << vec[vec.size() - 1];
	}
	
	return 0;
} 
