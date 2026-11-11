#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int N=510;
const int M=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,m,q,w[M],pos[M][30],t[M][30],len[M],dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,tmpt;
			cin>>a>>tmpt;
			len[a]++,pos[a][len[a]]=i,t[a][len[a]]=tmpt;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++){
			for(int k=j+1;k<=len[i];k++)dis[pos[i][j]][pos[i][k]]=dis[pos[i][k]][pos[i][j]]=min(dis[pos[i][j]][pos[i][k]],t[i][j]+t[i][k]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int j=1;j<=len[x];j++){
			for(int k=1;k<=len[y];k++)ans=min(ans,dis[pos[x][j]][pos[y][k]]+t[x][j]+t[y][k]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} 
