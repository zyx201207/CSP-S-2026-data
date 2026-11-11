#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;

int w[N];
int t[N][405] , a[N][405];
int k[N];

int c,n,m,d,q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
		
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<= m;i++){
		cin >> w[i];
	}
	
	
	for(int i = 1;i<=n;i++){
		cin >> k[i];
		for(int j = 1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << u * 5 + v << endl;
	}
	
	return 0;
}

/*
8 7
1 2 3 4 5 6 7 8

6 0
1 2 3 4 5 6

*/
