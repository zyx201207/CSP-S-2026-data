#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q;
long long w[N],k[505];
long long a[505][505],t[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<x*y-y+x<<"\n";
	}
	return 0;
} 
