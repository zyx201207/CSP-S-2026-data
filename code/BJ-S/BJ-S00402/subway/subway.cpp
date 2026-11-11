#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,w;
};
int c,n,m,d,q,a[500010];
int to[510][510],ct[500010];
node qwq[500010][25];
signed main(){
	memset(to,0x3f,sizeof(to));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		to[i][i]=0;
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int z,zzz;
			cin>>z>>zzz;
			qwq[z][++ct[z]]={i,zzz};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ct[i];j++){
			for(int k=j+1;k<=ct[i];k++){
				int x=qwq[i][j].v,y=qwq[i][k].v;
				to[x][y]=min(to[x][y],qwq[i][j].w+qwq[i][k].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			to[i][j]=min(to[i][j],to[j][i]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				to[i][j]=min(to[i][j],to[i][k]+to[j][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=LONG_LONG_MAX;
		for(int i=1;i<=ct[x];i++){
			for(int j=1;j<=ct[y];j++){
				ans=min(ans,qwq[x][i].w+to[qwq[x][i].v][qwq[y][j].v]+qwq[y][j].w);
			}
		}
		cout<<ans+a[x]+a[y]<<endl;
	}
	return 0;
}
