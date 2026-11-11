#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
//int w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m),k(n),x(q),y(q),ai(500005),ti(500005);
	vector<vector<int> > a,t;
	a.push_back(ai),t.push_back(ti);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ai[j]>>ti[j];
			
		}a.push_back(ai),t.push_back(ti);
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		long long ans=w[x[i]]+w[y[i]];
		for(int i=1;i<=n;i++){
			cout<<ans+1LL*n*(n-1);
		}
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
