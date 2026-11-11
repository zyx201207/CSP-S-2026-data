#include<bits/stdc++.h>
using namespace std;
int w[2005];
vector<int>g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			int b;
			cin>>b;
			cin>>t[b];	
			g[i].push_back(b);
			g[i].push_back(t[b]);
		}		
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;		
		cout<<w[x]+t[x]+w[y]+t[y];
	}
	return 0;
} 
