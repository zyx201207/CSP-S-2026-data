#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node{
	int id;
	int v;
};
vector<node> dian[500005];
int qz[505][505];
int zdl[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	memset(qz,0x3f3f3f3f,sizeof(qz));
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,b;
			cin>>a>>b;
			for(int k=0;k<dian[a].size();++k){
				qz[i][dian[a][k].id]=min(qz[i][dian[a][k].id],dian[a][k].v+b);
				qz[dian[a][k].id][i]=qz[i][dian[a][k].id];
			}
			dian[a].push_back(node{i,b});
		}
	}
	for(int i=1;i<=n;++i){
		for(int k=1;k<=n;++k){
			for(int j=1;j<=n;++j){
				if(i==k || k==j || i==j)continue;
				if(qz[i][k]==0x3f3f3f3f3f3f3f3f || qz[k][j]==0x3f3f3f3f3f3f3f3f)continue;
				qz[i][j]=min(qz[i][j],qz[i][k]+qz[k][j]);
				qz[j][i]=qz[i][j];
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<dian[l].size();++i){
			for(int j=0;j<dian[r].size();++j){
				int ont=dian[l][i].id;
				int sec=dian[r][j].id;
				if(ont==sec){
					ans=min(ans,w[l]+w[r]+dian[l][i].v+dian[r][j].v);
				}
				else ans=min(ans,w[l]+w[r]+dian[l][i].v+dian[r][j].v+qz[ont][sec]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
