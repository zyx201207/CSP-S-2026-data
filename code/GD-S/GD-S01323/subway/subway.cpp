#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5; 
int cid,n,m,d,q,W[M],K[N],f[N][N];
vector<int> a[N],t[N];
vector<pair<int,int>> vec[M];
int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++) W[i]=read();
	for(int i=1;i<=n;i++) {
		K[i]=read();
		a[i].resize(K[i]); t[i].resize(K[i]);
		for(int j=0;j<K[i];j++) a[i][j]=read(),t[i][j]=read();
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++) 
		for(int j=0;j<K[i];j++) vec[a[i][j]].push_back(make_pair(i,t[i][j]));
	for(int x=1;x<=m;x++) {
		for(pair<int,int> p1:vec[x]) {
			for(pair<int,int> p2:vec[x]) {
				int i=p1.first,ti=p1.second;
				int j=p2.first,tj=p2.second;
				if(i==j) continue;
				f[i][j]=min(f[i][j],ti+tj);
				f[j][i]=min(f[j][i],ti+tj);
			}
		}
	}
	for(int k=1;k<=n;k++) 
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--) {
		int x,y,ans=1e18;
		x=read(); y=read();
		for(pair<int,int> p1:vec[x]) {
			for(pair<int,int> p2:vec[y]) {
				int i=p1.first,ti=p1.second;
				int j=p2.first,tj=p2.second;
				ans=min(ans,f[i][j]+ti+tj);
			}
		}
		ans+=W[x]+W[y];
		cout<<ans<<'\n';
	}
}
