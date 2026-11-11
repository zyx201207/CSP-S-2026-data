#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> a[i];
	}
	for(int i=1; i<=d; i++){
		int x;
		cin >> x;
		int u[N],v[N];
		for(int j=1; j<=x; j++){
			cin >> u[j] >> v[j];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << a[x]+a[y] <<endl;
	}
	return 0;
} 
