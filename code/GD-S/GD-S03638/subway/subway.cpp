#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
ll n,m,d,c,Q,jl[505][505],dzk[500005];
vector<pair<ll,ll>>zan[500005];

int main(){
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	memset(jl,0x3f,sizeof(jl));
	for(ll i=1;i<=m;i++){
		scanf("%lld",&dzk[i]);
	}	
	ll aa,bb,cc;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&cc);
		jl[i][i]=0;
		while(cc--){
			scanf("%lld%lld",&aa,&bb);
			zan[aa].push_back({i,bb});
		} 
	}
	for(ll i=1;i<=m;i++){
		ll zd=zan[i].size();
//		cout<<i<<":"<<zd<<endl;
		for(ll u=0;u<zd;u++){
			for(ll v=u+1;v<zd;v++){
				ll ud=zan[i][u].first,uj=zan[i][u].second,
				   vd=zan[i][v].first,vj=zan[i][v].second;
//				cout<<ud<<' '<<vd<<' '<<uj+vj<<endl;
				if(jl[ud][vd]<=uj+vj)continue;
				jl[ud][vd]=jl[vd][ud]=uj+vj;
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<i<<' '<<j<<"|:"<<jl[i][j]<<endl;
//		}
//	}
//	cout<<endl;
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			if(i==k)continue;
			for(ll j=1;j<=n;j++){
				if(i==j||j==k)continue;
				jl[i][j]=min(jl[i][j],jl[i][k]+jl[k][j]);
			}
		}
	}
	while(Q--){
		scanf("%lld%lld",&aa,&bb);
		ll ans=1145141919810;
		for(pair<ll,ll> i:zan[aa]){
			for(pair<ll,ll> j:zan[bb]){
				ll id=i.first,ij=i.second,
				   jd=j.first,jj=j.second;
				ans=min(ans,ij+jj+jl[id][jd]);
			}
		}
		ans+=dzk[aa]+dzk[bb];
		printf("%lld\n",ans);
	}
	return 0;
} 
 
