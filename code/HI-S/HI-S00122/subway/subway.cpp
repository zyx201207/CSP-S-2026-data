#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e2 + 2;
const int M = 5e5 + 5;
int w[M], k[N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	int t;
	for(int i=1; i<=n; i++){
		cin>>k[i];
		for(int j=1; j<=2*k[i]; j++){
			if(j%2){
				int a;  cin>>a;
			}
			else{
				cin>>t;
			}
		}
	}
	
	while(q--){
		int x, y;
		cin>>x>>y;
		
		int sum=0;
		sum=w[x]+t*2+w[y];
		cout<<sum<<'\n';
	}
	
	return 0;
}
