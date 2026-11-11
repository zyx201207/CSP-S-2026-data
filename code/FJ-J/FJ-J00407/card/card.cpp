#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N] , cnt[N] , c[N] , s[N];
bool st[N];
vector<int> g[N] , p[N]; 
void add(int a , int b){
	g[a].push_back(b);
}
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	bool f = 1;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	for(int i = 1 ; i + 1 <= n ; i ++){
		if(a[i] > a[i + 1]){
			f = false;
			break;
		}
	}
	if(f){
		for(int i = 1 ; i <= n ; i ++){
			c[a[i]] ++;
		}
		for(int i = 1 ; i <= m ; i ++) s[i] = s[i - 1] + c[i];
		for(int i = 1 ; i <= m ; i ++){
			cout << s[i] << " ";
		}
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		p[a[i]].push_back(i);
	}
	for(int i = 1 ; i <= m ; i ++){
		for(int j = 0 ; j + 1 < p[i].size() ; j ++){
			add(p[i][j] , p[i][j + 1]);
		}
	} 
	for(int k = 1 ; k <= n ; k ++){
		memset(st , false , sizeof(st));
		for(int i = k ; i <= n ; i ++){
			for(auto x : g[a[i]]){
				for(int j = i ; j < x ; j ++){
					st[j] = 1;
				}
			}
		}
		for(int i = k ; i <= n ; i ++){
			if(!st[i]){
				cnt[a[i]] ++;
			}
		}
	}
	for(int i = 1 ; i <= m ; i ++) cout << cnt[i] << " ";
	return 0;
}

/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
