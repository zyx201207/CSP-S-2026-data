#include<bits/stdc++.h>
#define pr pair<int,int>
#define fst first
#define snd second
#define ll long long
using namespace std;
const int N=501,M=5e5+1;
int c,n,m,d,q;
ll ans,w[M],f[N][N];
vector<pr>b[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q,memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,v;j<=k;j++)cin>>x>>v,b[x].push_back({i,v});
	}
	for(int i=1;i<=m;i++)
		for(pr j:b[i])for(pr k:b[i])f[j.fst][k.fst]=f[k.fst][j.fst]=j.snd+k.snd;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y,ans=LLONG_MAX;
		for(pr j:b[x])for(pr k:b[y])ans=min(ans,j.snd+k.snd+f[j.fst][k.fst]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
/*
ÉñÃØÔÄ¶ÁÀí½â 
*/
