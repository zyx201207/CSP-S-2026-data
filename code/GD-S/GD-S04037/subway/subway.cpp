#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
vector<vector<pair<int,pair<int,int> > > > g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	g.resize(m+5);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y2,z1;
		cin>>x>>y2>>z1;
		for(int j=2;j<=x;j++){
			int y,z;
			cin>>y>>z;
			g[y2].push_back({y,{z,z1}});
			g[y].push_back({y2,{z,z1}});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long cnt=w[x]+w[y];
		for(auto v:g[x]){
			if(v.first==y){
				cnt+=(v.second.first+v.second.second);
				break;
			}
		}
		cout<<cnt<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 

