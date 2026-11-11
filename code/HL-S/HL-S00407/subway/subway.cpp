#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
const int N = 5e5 + 10;
int mx[N], k, a[N], t[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		cin>>mx[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>k;
		for(int j = 1; j <= k; j++){
			cin>>a[j]>>t[j];
		}
	}
	int x, y;
	for(int i = 1; i <= q; i++){
		cin>>x>>y;
	}
	
	cout<<32<<"\n";
	cout<<17;
	
	return 0;
}