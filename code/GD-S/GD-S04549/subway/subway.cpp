#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define pil pair<int,long long>
using namespace std;

const int M=5e5+10,N=510;

int casee,n,m,d,Q;
ll inf;

struct node{
	ll w;
	vector <pil> vec;
}a[M];

ll f[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&casee,&n,&m,&d,&Q);
	rep(i,1,m) scanf("%lld",&a[i].w);
	rep(i,1,n){
		int k;scanf("%d",&k);
		rep(j,1,k){
			int id;ll len;
			scanf("%d%lld",&id,&len);
			a[id].vec.push_back({i,len});
		} 
	}
	memset(f,0x3f,sizeof(f));
	inf=f[0][0];
	rep(i,1,n) f[i][i]=0;
	rep(i,1,m){
		for(auto prs:a[i].vec){
			for(auto prt:a[i].vec){
				int s=prs.first,t=prt.first;
				if(s==t) continue;
				f[s][t]=min(f[s][t],prs.second+prt.second);
				f[t][s]=min(f[t][s],prs.second+prt.second);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			if(k==i) continue;
			if(f[i][k]>=inf) continue;
			rep(j,1,n){
				if(k==i||i==j||j==k||f[k][j]>=inf) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}	
	}
	while(Q--){
		int u,v;
		ll ans=inf;
		scanf("%d%d",&u,&v);
		for(auto prs:a[u].vec){
			for(auto prt:a[v].vec){
				int s=prs.first,t=prt.first;
				ans=min(ans,a[u].w+a[v].w+prs.second+prt.second+f[s][t]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0; 
} 
