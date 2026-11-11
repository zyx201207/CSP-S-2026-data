#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> mp;
//	若桌面上没有点数为 k 的牌，就将这张牌放在最右端
//	否则，收走桌面上点数为 k 的牌及其右侧的所有牌，再把这张牌放在最右端。
	int n,m; cin >> n >> m;
	set<int> s;
	string s1="";
	while (n--){
		for (int i=1; i<=m; i++){
			cin >> a[i];
	
		
		}
		for (int i=1; i<=m; i++){
			cout  << a[i];
		
		}
		
		m--;
	}
	
	return 0;
} 
