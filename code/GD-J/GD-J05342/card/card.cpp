#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<int , int>

int n , m , a[N];
int last[N] , ans[N];//实时维护当前有多少种方法能够跳到当前数字 

int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		last[a[i]] = max(last[a[i]] , i);
	}
	for(int i = 1 ; i <= n ; i++){
		ans[a[i]]++; 
		if(i != 1 && last[a[i - 1]] == i - 1) ans[a[i]] += ans[a[i - 1]]; 
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
	return 0;
} 

/*
FC /W D:\GD-J05342\card\card.ans D:\GD-J05342\card\card.out

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
