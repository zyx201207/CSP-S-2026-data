#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;
const int MAXN = 5e5 + 10;
const int MAXM = 5e2 + 10;
const int MAXD = 20 + 1;
const ll inf = 2e18;

int ID,m,n,mxd,q;
int tw[MAXN];
int len[MAXM];
vector<int>a[MAXM],t[MAXM];
int cnt[MAXN];
array<int,2>ps[MAXN][MAXD];
ll dis[MAXM][MAXM];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ID,&m,&n,&mxd,&q);//m=500,n=5e5
	FL(i,1,n) scanf("%d",&tw[i]);
	FL(i,1,m){
		scanf("%d",&len[i]);
		a[i].resize(len[i]+1),t[i].resize(len[i]+1);
		FL(j,1,len[i]){
			scanf("%d%d",&a[i][j],&t[i][j]);
			ps[a[i][j]][++cnt[a[i][j]]]={i,t[i][j]};
			assert(cnt[a[i][j]]<=mxd);
		}
	}
	FL(i,1,m) FL(j,1,m) dis[i][j]=(i==j?0:inf);
	FL(u,1,n)
		FL(i,1,cnt[u]){
			FL(j,i+1,cnt[u]){
				int id1=ps[u][i][0],id2=ps[u][j][0];
				int t1=ps[u][i][1],t2=ps[u][j][1];
				dis[id2][id1]=dis[id1][id2]=min(dis[id1][id2],(ll)t1+t2);
			}
		}
	FL(k,1,m){
		FL(i,1,m){
			if(i==k||dis[i][k]==inf) continue;
			FL(j,1,m){
				if(i==j||j==k||dis[k][j]==inf) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int St,Ed;
		ll ans=inf;
		scanf("%d%d",&St,&Ed);
		FL(i,1,cnt[St])
			FL(j,1,cnt[Ed])
				if(dis[ps[St][i][0]][ps[Ed][j][0]]!=inf) ans=min(ans,(ll)ps[St][i][1]+dis[ps[St][i][0]][ps[Ed][j][0]]+ps[Ed][j][1]);
		printf("%lld\n",ans+tw[St]+tw[Ed]);
	}
}
