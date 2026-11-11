#include<bits/stdc++.h>
using namespace std;
#define fir first 
#define sec second
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
int f[1010][1010],w[500010];
vector<pair<int,int> > st[500010];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=1,a,t;j<=k;++j){
			cin>>a>>t;
			st[a].push_back(make_pair(i,t));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)st[i].size();++j)
		for(int k=0;k<(int)st[i].size();++k){
			pair<int,int> x=st[i][j],y=st[i][k];
			f[x.fir][y.fir]=min(f[x.fir][y.fir],x.sec+y.sec);
		}
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,s,e;i<=q;++i){
		cin>>s>>e;
		int ans=inf;
		for(int j=0;j<(int)st[s].size();++j)
		for(int k=0;k<(int)st[e].size();++k){
			pair<int,int> x=st[s][j],y=st[e][k];
			ans=min(ans,f[x.fir][y.fir]+x.sec+y.sec+w[s]+w[e]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
