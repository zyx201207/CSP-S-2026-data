//subway GYSM 
#include<bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int INF=1ll<<60;
inline void read(int &x){
	char c;
	while(!isdigit(c=getchar()));
	x=c-'0';
	while(isdigit(c=getchar())) x=x*10+c-'0';
}
inline void write(int x,bool f=1){if(x||f) write(x/10,0),putchar(x%10+'0');}
int n,m,q,w[500010],k,a,b,ans;
vector<pii> t[500010];
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(n),read(n),read(m),read(q),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		read(k);
		while(k--){
			read(a),read(b);
			t[a].push_back({b,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto x:t[i]){
			for(auto y:t[i]){
				dis[x.s][y.s]=min(dis[x.s][y.s],x.f+y.f);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		read(a),read(b);
		ans=INF;
		for(auto x:t[a]){
			for(auto y:t[b]) ans=min(ans,x.f+y.f+dis[x.s][y.s]);
		}
		write(ans+w[a]+w[b]);putchar('\n');
	}
	return 0;
}
