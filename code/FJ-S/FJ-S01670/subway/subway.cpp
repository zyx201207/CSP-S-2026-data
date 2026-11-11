#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=510;
const ll M=5e5+10;
ll c,n,m,d,q,w[M],k;
struct Station{
	ll x,t;
};
vector<Station> sa[M];
ll f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=n;i++){
		ll k=read();
		while(k--){
			ll pos,t;
			pos=read();
			t=read();
			Station tmp;
			tmp.x=i;
			tmp.t=t;
			sa[pos].push_back(tmp);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		for (unsigned int j=0;j<sa[i].size();j++){
			for (unsigned int k=j+1;k<sa[i].size();k++){
				ll x=sa[i][j].x;
				ll y=sa[i][k].x;
				ll t=sa[i][j].t+sa[i][k].t;
				f[x][y]=min(f[x][y],t);
				f[y][x]=min(f[y][x],t);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if(i==k||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		x=read();
		y=read();
		ll ans=1e18;
		for (unsigned int i=0;i<sa[x].size();i++){
			for (unsigned int j=0;j<sa[y].size();j++){
				ll p1=sa[x][i].x;
				ll p2=sa[y][j].x;
				ans=min(ans,f[p1][p2]+w[x]+w[y]+sa[x][i].t+sa[y][j].t);
			}
		}
		printf("%lld\n",ans);
	}
}
//15:08
