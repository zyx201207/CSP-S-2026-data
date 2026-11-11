#include <bits/stdc++.h>
using namespace  std;

long long c,n,m,d,q,k;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<long long>w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<vector<long long> >a(n+1,vector<long long>(m+1,0));
	vector<vector<long long> >t(n+1,vector<long long>(m+1,0));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		long long x,y;cin>>x>>y;
		long long sp=w[x];
		while(){
			 
		}
	}
	return 0;
}
