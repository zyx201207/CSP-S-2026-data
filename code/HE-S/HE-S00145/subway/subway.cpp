#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int c , n , m , d , q ,k;
long long w[N],a[500][N],t[500][N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k*2;j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	for(int i=1;i<n;i++){
		cin>>x[i]>>y[i];
	}
	
	
	
	return 0;
}
/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
*/
