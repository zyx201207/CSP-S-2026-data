#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c=read(),n=read(),m=read(),d=read(),q=read(),w[500010];
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
//	cout<<1;
	vector<pair<ll,ll> > a[500010];
	ll b[510][510];
	for(int i=1;i<=n;i++){
		ll k=read();
		for(int j=0;j<k;j++){
			a[read()].push_back({i,read()});
		}
	}
//	cout<<2;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j]=11e18+1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int z=j+1;z<a[i].size();z++){
				int fr=a[i][j].first,to=a[i][z].first;
				b[fr][to]=min(b[fr][to],a[i][z].second+a[i][j].second);
				b[to][fr]=min(b[to][fr],a[i][z].second+a[i][j].second);
//				cout<<i<<":   "<<fr<<"->"<<to<<"  "<<a[i][z].second+a[i][j].second<<"\n";
			}
		}
	}
//	cout<<3;
	for(int i=1;i<=n;i++){
		b[i][i]=0;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=n;z++){
				if(b[i][j]+b[i][z]<b[j][z]){
					b[j][z]=b[i][j]+b[i][z];
					b[z][j]=b[i][j]+b[i][z];
				}
			}
		}
	}
//	cout<<4;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" -> "<<j<<" : "<<b[i][j]<<"\n";
//		}
//	}
	for(int i=0;i<q;i++){
		ll u=read(),v=read(),ans=1e18;
		for(int j=0;j<a[u].size();j++){
			for(int z=0;z<a[v].size();z++){
				ans=min(ans,a[u][j].second+a[v][z].second+b[a[u][j].first][a[v][z].first]+w[u]+w[v]);
//				cout<<u<<" -> ("<<a[u][j].first<<") -> ("<<a[v][z].first<<") -> "<<v<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
