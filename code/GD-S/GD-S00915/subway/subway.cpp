#include<bits/stdc++.h>
#define int long long
using namespace std;
struct cc{
	int x,t;
};
int n,m,a[500010],c,k,ans,d,y,x,q,t[1000][1000],l,r,w[500010],kk;
vector<cc> e[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	memset(t,0x3f3f3f,sizeof(t));
	for(int u=1;u<=m;u++){
		for(int i=0;i<e[u].size();i++){
			for(int j=i+1;j<e[u].size();j++){
				int v1=e[u][i].x,t1=e[u][i].t;
				int v2=e[u][j].x,t2=e[u][j].t;
//				cout<<u<<" "<<v1<<" "<<v2<<" "<<t1<<" "<<t2<<endl;
				t[v1][v2]=min(t[v1][v2],t1+t2);
				t[v2][v1]=min(t[v2][v1],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j) t[i][j]=0;
				t[i][j]=t[j][i]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		cin>>l>>r;
		int mi=1e18;
		for(int i=0;i<e[l].size();i++){
			for(int j=0;j<e[r].size();j++){
				int v1=e[l][i].x,v2=e[r][j].x,t1=e[l][i].t,t2=e[r][j].t;
				mi=min(mi,t[v1][v2]+w[l]+w[r]+t1+t2);
			}
		}
		cout<<mi<<endl;
	}
}
