#include<bits/stdc++.h>
using namespace std;

const int N=505,T=5e5+5;
int n,q,m,d,k;
vector<pair<int,int> >E[T];
long long f[N][N],w[T],inf,ans;
inline void chkmin(long long &x,long long y){x=x<y?x:y;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1,k,t,pos;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>pos>>t;
			E[pos].push_back({t,i});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i)
		for(pair<int,int>j:E[i])
			for(pair<int,int>k:E[i]) chkmin(f[j.second][k.second],j.first+k.first);
	inf=f[0][0];
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(f[i][k]==inf) continue;
			for(int j=1;j<=n;++j) chkmin(f[i][j],f[i][k]+f[k][j]);
		}
	}
	int s,t;
	while(q--){
		cin>>s>>t,ans=inf;
		for(pair<int,int>i:E[s])
			for(pair<int,int>j:E[t]) chkmin(ans,f[i.second][j.second]+i.first+j.first);
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
