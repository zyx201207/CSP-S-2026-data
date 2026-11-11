#include<bits/stdc++.h>
# define Maxn 500005 
# define ll long long
# define inf 100000000000000000
# define fir first
# define sec second
using namespace std;
int cid,n,m,D,q,K,x,y;
int w[Maxn];

vector<pair<int,int>> vec[Maxn];

ll dis[505][505]; 

namespace Read{
	int fg;
	char ch;
	void read(int &x) {
		fg=1,x=0;
		ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') fg=-1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
		x*=fg;
	}
};
using namespace Read;

int main() {
//	freopen("subway3.in","r",stdin);
//	freopen("my.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(cid),read(m),read(n),read(D),read(q);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1;i<=m;i++) {
		read(K);
		for(int j=1;j<=K;j++) read(x),read(y),vec[x].push_back({i,y});
	} 
	
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=n;i++) {
		for(pair<int,int> j:vec[i]) {
			for(pair<int,int> k:vec[i]) {
				if(j.fir!=k.fir)
				dis[j.fir][k.fir]=min(dis[j.fir][k.fir],(ll)j.sec+k.sec);
			}
		}
	}
	
	for(int k=1;k<=m;k++) {
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=m;j++)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	
	while(q--) {
		read(x),read(y);
		ll ans=inf;
		for(pair<int,int> i:vec[x]) {
			for(pair<int,int> j:vec[y])
			ans=min(ans,i.sec+dis[i.fir][j.fir]+j.sec+w[x]+w[y]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
