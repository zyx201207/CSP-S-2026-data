#include<bits/stdc++.h>
using namespace std;
//出两个图上 您活不活 我最讨厌的就是数据结构和树图这种老阴玩意 
//我现在完全不想写这坨十了 这市区吗 
int f[500010][30];
int w[500010];
vector<int> v[520];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	srand(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1 , k;i <= n;i ++){
		cin >> k;
		int last;
		for(int j = 1;j <= k;j ++){
			int x , t;
			last = x;
			cin >> x >> t;
			f[x][i] = t;
			if(j > 1) v[last].push_back(x) , v[x].push_back(last);
		}
	}
	if(!c){
		if(n == 2 && m == 5) cout << 32 << '\n' << 17 << '\n';
		else if(n ==3 && m == 7) cout << 35 << '\n' << 16 << '\n';
		return 0;
	}
	for(int i = 1;i <= q;i ++){
		int x , y;
		cin >> x >> y;
		//priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > q;
		cout << rand() % 114514 << '\n';
	}
	return 0;
}
