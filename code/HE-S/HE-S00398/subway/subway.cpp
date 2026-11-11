#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')w=w*10+c-'0',c=getchar();
	return w;
}
const int H=5e5+10,N=510;
int c,n,m,d,q,h[N];
long long dij[N][N];
vector<pair<int,int>> belong[H];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(dij,0x3f,sizeof(dij));
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		h[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int p=1;p<=k;p++){
			int q=read(),w=read();
			for(auto p:belong[q]){
				dij[p.first][i]=dij[i][p.first]=min(dij[i][p.first],(long long)w+p.second);
			}
			belong[q].push_back({i,w});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int p=1;p<=n;p++){
				dij[i][p]=min(dij[i][p],dij[i][k]+dij[k][p]);
			}
		}
	}
	while(q--){
		int ttx,tty;
		long long mx=1e18;
		ttx=read();tty=read();
		for(auto i:belong[ttx]){
			for(auto p:belong[tty]){
				if(i.first==p.first){
					mx=min(mx,(long long)i.second+p.second);continue;
				}
				mx=min(mx,dij[i.first][p.first]+i.second+p.second);
			}
		}
		cout<<mx+h[ttx]+h[tty]<<'\n';
	}
	return 0;
}
