#include<bits/stdc++.h>
const int N=(1<<24);
#define ll long long
using namespace std;
ll T,n,m,x,a[1000005],ans,b[5005][5005],c[5005][5005];
bool vi[1000005];
vector<ll> g[1000005];
void dfs(ll i){
	vi[i]=1;
	for(ll j=0;j<(ll)g[i].size();j++){
		b[i][g[i][j]]=1;
		for(ll k=1;k<i;k++) b[k][g[i][j]]=min(b[k][g[i][j]],b[k][i]+1);
		if(!vi[g[i][j]]) dfs(g[i][j]);
	}
	for(ll j=0;j<(ll)g[i].size();j++){
		if(!vi[g[i][j]]) dfs(g[i][j]);
	}
}
void dfs2(ll i){
	vi[i]=1;
	for(ll j=0;j<(ll)g[i].size();j++){
		c[i][g[i][j]]=1;
		for(ll k=1;k<i;k++) if(b[k][g[i][j]]==b[k][i]+1) c[k][g[i][j]]=min(3LL,c[k][g[i][j]]+1);
		if(!vi[g[i][j]]) dfs2(g[i][j]);
	}
	for(ll j=0;j<(ll)g[i].size();j++){
		if(!vi[g[i][j]]) dfs2(g[i][j]);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>T;
	memset(b,0x3f,sizeof(b));
	while(T--){
		cin>>n>>m,ans=0;
		for(ll i=1;i<=n+1;i++) g[i].clear();
		for(ll i=1;i<=n+1;i++){
			for(ll j=1;j<=n+1;j++){
				b[i][j]=(ll)0x3f3f3f3f3f3f3f3f,c[i][j]=0;
			}
		}
		for(ll i=1;i<=n+1;i++) vi[i]=0,a[i]=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i],x=lower_bound(a+1,a+1+i,a[i]-m)-a;
			for(ll j=x;j<i;j++) g[j].push_back(i);
		}
		for(ll i=1;i<=n;i++) if(!vi[i]) dfs(i);
		for(ll i=1;i<=n;i++) vi[i]=0;
		for(ll i=1;i<=n;i++) if(!vi[i]) dfs2(i);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(c[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
