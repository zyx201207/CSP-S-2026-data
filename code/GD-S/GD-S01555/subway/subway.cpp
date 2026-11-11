#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[505];
long long a[505][30005];
long long t[505][30005];
long x,y;
struct ljb{
	vector <int> path;
	vector <int> cost; 
};
void calc(){
	long long ans = 0;
	ans+=w[x]+w[y];
	
	cout<<ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i<=q;i++){
		cin>>x>>y;
		calc();
	}
	return 0;
}
