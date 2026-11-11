#include <bits/stdc++.h>
#define ll long long
using namespace std;
int C,n,m,d,q;
vector<pair<int,ll>> belong[500010];
ll f[510][510],w[500010];
inline ll read(){
	ll res=0ll,neg=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) res=res*10ll+ch-'0',ch=getchar();
	return res*neg;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	clock_t st=clock();
	memset(f,0x3f,sizeof(f));
	cin>>C>>n>>m>>d>>q;
//	C=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
//	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
//		kk=read();
		for(int j=1;j<=kk;j++){
			ll aa,bb;
			cin>>aa>>bb;
//			aa=read(),bb=read();
			belong[aa].push_back({i,bb});
		}
	}
	for(int i=1;i<=m;i++){
		if(belong[i].size()<=1) continue;
		int len=belong[i].size();
		for(int uu=0;uu<len;uu++){
			ll u=belong[i][uu].first,tu=belong[i][uu].second;
			for(int vv=0;vv<len;vv++){
				ll v=belong[i][vv].first,tv=belong[i][vv].second;
				if(u==v) continue;
				f[u][v]=min(f[u][v],tu+tv);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int s,tt;
		cin>>s>>tt;
//		s=read(),tt=read();
		ll ans=1e18;
		int lens=belong[s].size(),lent=belong[tt].size();
		for(int uu=0;uu<lens;uu++){
			ll u=belong[s][uu].first,tu=belong[s][uu].second;
			for(int vv=0;vv<lent;vv++){
				ll v=belong[tt][vv].first,tv=belong[tt][vv].second;
				ans=min(ans,f[u][v]+tu+tv);
			}
		}
		cout<<ans+w[s]+w[tt]<<'\n';
	}
//	clock_t en=clock();
//	cout<<1.0*(en-st)/CLOCKS_PER_SEC<<'\n';
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
