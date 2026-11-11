#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e2+5,M=5e5+5,inf = 4e18;
int w[M],f[N][N],n,m,cc,d,q,k[N];
vector<pii> l[M];
inline read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> cc>>n >> m>>d>>q;
	//cc=read(),n=read(),m=read(),d=read(),q=read();
	for(int i = 1;i<=m;i++){
		cin >> w[i];
		//w[i]=read();
	}
	for(int i = 1;i<=n;i++){
		cin >> k[i];
		//k[i]=read();
		for(int j = 1;j<=k[i];j++){
			int u,v;
			cin >> u >> v;
			//u=read(),v=read();
			l[u].push_back(make_pair(i,v));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i<=n;i++) f[i][i]=0;
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<l[i].size();j++){
			for(int k = j+1;k<l[i].size();k++){
				int u = l[i][j].fi,v=l[i][k].fi;
				int x = l[i][j].se,y=l[i][k].se;
				//cout << u << " " << v<<" "<<x<<" "<<y<<"\n";
				f[u][v]=min(f[u][v],x+y);
				f[v][u]=min(f[v][u],x+y);
			}
		}
	}
	floyd();
	/*for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}*/
	while(q--){
		int fr,to;
		cin >> fr >> to;
		//fr=read(),to=read();
		int ans = inf;
		for(int i = 0;i<l[fr].size();i++){
			for(int j = 0;j<l[to].size();j++){
				int u=l[fr][i].fi,v=l[to][j].fi;
				int x=l[fr][i].se,y=l[to][j].se;
				ans=min(ans,f[u][v]+x+y);
			}
		}
		cout << ans+w[to]+w[fr] << "\n";
	}
	return 0;
}
