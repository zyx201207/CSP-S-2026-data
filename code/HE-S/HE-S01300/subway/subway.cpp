#include<bits/stdc++.h>
using namespace std;
const int M = 500;
const int X = 1e5 + 10;
const int N = 1e6 + 10;
int w[M];
vector<int>edge[N];
int val[M][X];
int tot[N];
struct stu{
	int to , w;
};
stu ch[N][30];
int c , n , m , d , p , k;
int a , t;
struct stk{
	int pos , to , v;
	bool  operator  < (const stk & z) const{
		return v > z.v;
	}
};
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i];
	for(int i = 1 ; i <= n ; i ++){
		cin >> k;
		for(int j = 1 ; j <= k ; j ++){
			cin >> a >> t;
			ch[a][++ tot[a]].to = i;
			ch[a][tot[a]].w = t;
			edge[i].push_back(a);
			val[i][a] = t;
		}
	}
	int x , y;
	queue<int> q;
	for(int i = 1 ; i <= p ; i ++){
		cin >> x >> y;
		for(int i = 1 ; i <= tot[x] ; i ++){
//			q.push({ch[a][i].to , x , ch[a][i].w});
		}
	}
	for(int i = 1 ; i <= n ; i ++) cout << rand() << "\n";
	return 0;
}
