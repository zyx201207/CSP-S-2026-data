#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e2+5,MAXM=5e5+5;
int n,m,c,d,q,dis[MAXN][MAXN],w[MAXM],k[MAXN];
vector<pair<int,int> > st[MAXM];
int read(){
	int num=0;char ch=getchar();
	while('0'>ch || ch>'9') ch=getchar();
	while('0'<=ch && ch<='9') num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<read();
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=2e9;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++) w[i]=read();
//	cout<<w[315225 ]<<' '<<w[420528]<<endl;
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a=read(),t=read();
			st[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:st[i]){
			for(auto v:st[i]){
				if(u.first==v.first) continue;
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<i<<'-'<<j<<':'<<dis[i][j]<<endl;
//	}
	while(q--){
		int a,b;cin>>a>>b;
		int ans=4e18;
		for(auto i:st[a]){
			for(auto j:st[b]){
		//		cout<<i.first<<'-'<<j.first<<endl;
		//		cout<<dis[i.first][j.first]<<' '<<w[a]+w[b]<<' '<<j.second+i.second<<endl;
				ans=min(ans,dis[i.first][j.first]+w[a]+w[b]+j.second+i.second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
