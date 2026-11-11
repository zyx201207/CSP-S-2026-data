#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5*5+5;
int w[MAX];
vector<int> g[MAX];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back(t);
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=0;
		for(int i=x;i<=y;i++){
			for(int j=0;j<g[i].size();j++)
				sum+=g[i][j];
		}
		cout<<sum+w[x]+w[y]<<'\n';
	}
	return 0;
}

