#include<bits/stdc++.h>
#define int long long
#define N 1005
using namespace std;
int c,d,q;//q个询问
int m,n;//n条线,m个点
int w[N];
int t[505][N],l[505][N];
int f[N][N];//最短路
int to[N][N];
int a[500005][3];
struct di {
	int i,val;
	bool operator <(di x)const {
		return x.val<val;
	}
};
void dij(int st) {
	priority_queue<di> q;
	q.push({st,0});
	f[st][st]=0;
	while(!q.empty()) {
		di x=q.top();
		q.pop();
		int now=x.i,val=x.val;
		for(int i=1; i<=m; i++) {
			if(i!=now&&val+to[now][i]<f[st][i]) {
				f[st][i]=val+to[now][i];
				q.push({i,val+to[now][i]});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	if(c>=1&&c<=11) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=m; j++) f[i][j]=to[i][j]=1e10;
		}
		for(int i=1; i<=n; i++) {
			int len;
			cin>>len;
			for(int j=1; j<=len; j++) {
				cin>>l[i][j]>>t[i][j];
				for(int x=j-1; x>=1; x--) {
					to[l[i][j]][l[i][x]]=min(to[l[i][j]][l[i][x]],t[i][j]+t[i][x]);
					to[l[i][x]][l[i][j]]=to[l[i][j]][l[i][x]];
				}
			}
		}
		for(int i=1; i<=q; i++) {
			int x,y;
			cin>>x>>y;
			if(f[x][y]==1e10) dij(x);//优化方向:对dij进行优化
			cout<<f[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	else if(c==20||c==21){
		int mn=1e10;
		for(int i=1; i<=n; i++) {
			int len;
			cin>>len;
			for(int j=1; j<=len; j++) {
				int x,y;
				cin>>x>>y;
				a[x][i]=y;
				if(i==2&&a[x][1]!=0) mn=min(mn,a[x][1]+a[x][2]);
			}
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			int ans=1e10;
			bool fl=0;
			if(a[l][1]*a[r][1]!=0){
				ans=min(ans,a[l][1]+a[r][1]);
				fl=1;
			}
			if(a[l][2]*a[r][2]!=0){
				ans=min(ans,a[l][2]+a[r][2]);
				fl=1;
			}
			if(a[l][1]*a[r][1]==0&&a[l][2]*a[r][2]==0){
				ans=min(ans,mn+max(a[l][1],a[l][2])+max(a[r][1],a[r][2]));
			}
			cout<<ans+w[l]+w[r]<<'\n';
		}
	}
	return 0;
}
