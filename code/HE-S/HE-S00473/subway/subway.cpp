#include <bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,c,d,q,w[N];
int k[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	int a,t;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a >> t;
		}
	}
	for(int x,y,i = 1;i <= q;i++){
		cin >> x >> y;
		cout << w[x]+w[y] << "\n";
	}
	return 0;
}

