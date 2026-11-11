#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q,go[N][N],w[N],ans,r[N][N];
bool b[N];
void dfs(int x,int cnt,int y){
	if(cnt>ans)return ;
	if(x==y){
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(go[x][i]!=0x3f3f3f3f&&!b[i]){
			b[i]=1;
			dfs(i,cnt+go[x][i],y);
			b[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	memset(go,0x3f,sizeof go);
	while(m--){
		int k;
		cin>>k;
		int p[N][2];
		for(int i=1;i<=k;i++){
			cin>>p[i][0]>>p[i][1];
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				go[p[i][0]][p[j][0]]=min(go[p[i][0]][p[j][0]],p[i][1]+p[j][1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(r[j][i]){
				r[i][j]=r[j][i];
				continue;
			}
			if(i==j){r[i][j]=0;continue;
			}
			if(go[i][j]!=0x3f3f3f3f){
				r[i][j]=w[i]+w[j]+go[i][j];
				r[j][i]=w[i]+w[j]+go[i][j];
			}else{
				ans=2e9;
				memset(b,0,sizeof b);
				dfs(i,0,j);
				r[i][j]=w[i]+w[j]+ans;
				r[j][i]=w[i]+w[j]+ans;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<r[x][y]<<'\n';
	}
	return 0;
}
