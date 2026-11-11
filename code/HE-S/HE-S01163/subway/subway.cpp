#include<bits/stdc++.h>
using namespace std;
//int head[500010],to[500010],val[500010],nxt[500010];
//int cnt=0;
//void add(int x,int y,int v){
//	cnt++;
//	to[cnt]=y;
//	val[cnt]=v;
//	nxt[cnt]=head[x];
//	head[x]=cnt;
//}
int w[500010]= {};
int a[510][100001];
int t[510][100001];
int s[510][100001];
int num[500010]= {};
int k[510];
int vis[100001];
int visx[100001];
long long mxa=1e18;
void dfs(int x,int y,int sta,long long maxx) {
//	cout<<sta<<endl;
	if(sta==y) {
		if(maxx<mxa) {
			mxa=maxx;
		}
		return ;
	}
	for(int i=1; i<=num[sta]; i++) { //xianlu
		int xianlu=s[sta][i];
		
		if(visx[xianlu]) continue;
		visx[xianlu]=1;
//		cout<<xianlu<<endl;
		for(int j=1; j<=k[xianlu]; j++) { //chezhan
//			cout<<a[i][j]<<' ';
			if(a[xianlu][j]!=sta&&vis[a[xianlu][j]]==0) {
				vis[a[xianlu][j]]=1;
				long long nmax=maxx+1LL*t[xianlu][sta]+1LL*t[xianlu][a[xianlu][j]];
//				cout<<sta<<' '<<t[xianlu][sta]<<' '<<t[xianlu][a[xianlu][j]]<<endl;
				dfs(x,y,a[xianlu][j],nmax);
				vis[a[xianlu][j]]=0;
			}
		}
		vis[xianlu]=0;
	}
	return ;
}
//void dfs2(int x,int y,int lst,int maxx){
//	
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
//	if(d<=2){
//		for(int i=1;i<=n;i++){
//			cin>>k[i];
//			for(int j=1;j<=k[i];j++){
//				cin>>a[i][j];
//				cin>>t[i][j];
//			}
//			if(k[i]==2){
//				if(nxt[a[i][1]][1]==0){
//					nxt[a[i][1]][1]=a[i][2];
//					nxt[a[i][1]][2]=t[i][2];
//				}
//			}
//		}
//		for(int i=1;i<=q;i++){
//			int x,y;
//			cin>>x>>y;
//			long long maxx=0;
//			while(nxt[j].to==y){
//				
//			}
//		}
//		return 0;
//	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			s[a[i][j]][++num[a[i][j]]]=i;
		}
	}
//	for(int i=1; i<=m; i++) {
//		for(int j=1; j<=num[i]; j++) {
//			cout<<s[i][j]<<' ';
//
//		}
//		cout<<endl;
//	}
	for(int i=1; i<=q; i++) {
		for(int j=1;j<=n;j++){
			visx[j]=0;
		}
		int x,y;
		cin>>x>>y;
		mxa=1e9;
		vis[x]=1;
		dfs(x,y,x,0);
		vis[x]=0;
		cout<<mxa+w[x]+w[y]<<endl;
	}
	return 0;
}
