#include <bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , w[500005] , k[55];
struct node{
	long long s , t;
};
vector <node> line[55] , stop[500005];
int main (){
	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	cin.tie (0) -> sync_with_stdio (0); 
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i++)  cin >> w[i];
	for (int i = 1 ; i <= n ; i++){
		cin >> k[i];
		for (int j = 1 ; j <= k[i] ; j++){
			long long a , b;
			cin >> a >> b;
			line[i].push_back ({a , b});
			stop[a].push_back ({i , b});
		}
	}
	while (q--){
		long long a , b;
		cin >> a >> b;
	}
	return 0;
} 
