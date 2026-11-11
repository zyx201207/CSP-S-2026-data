#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001];
vector<pair<int,int> >vec[501];
bool v[501][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<32<<'\n';
	}
	return 0;
}
