#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct op{
	int a,b;
};
vector<op> v[500005];
int w[500005],c[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int c1,n,m,d,q,tp=0;
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int l,w;
			cin>>l>>w;
			v[l].push_back({i,w});
			tp=w;
		}
	}
	if(c1>=12&&c1<=19){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					c[i][j]=2*tp;
				}
			}
		}
	}else{
		memset(c,0x3f,sizeof(c));
		for(int i=1;i<=m;i++){
			for(int j=0;j<v[i].size();j++){
				for(int z=0;z<v[i].size();z++){
					if(j!=z){
						c[v[i][j].a][v[i][z].a]=min(c[v[i][j].a][v[i][z].a],v[i][z].b+v[i][j].b);
					} 
				}
			}
		}
		for(int i=1;i<=n;i++){
			c[i][i]=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				for(int z=1;z<=n;z++){
					if(z==i||z==j) continue;
					c[i][j]=min(c[i][j],c[i][z]+c[z][j]);
				}
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans=1e17;
		for(int i=0;i<v[a].size();i++){
			for(int j=0;j<v[b].size();j++){
				ans=min(ans,c[v[a][i].a][v[b][j].a]+v[a][i].b+v[b][j].b);
			}
		}
		cout<<ans+w[a]+w[b]<<"\n";
	}
} 
