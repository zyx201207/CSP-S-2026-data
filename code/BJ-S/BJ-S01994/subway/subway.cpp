#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxm=5e5+10;
const ll maxn=510;
ll status;
FILE *fl;
ll c,n,m,d,q;
ll w[maxm];
ll k[maxn];
list<pair<ll,ll>>interchange[maxm];
//ll interccnt=0;
//ll a[maxm];
//ll astart[maxm]
ll alen[maxm];
//ll t[maxm];
//ll apos=0;
ll disline[maxn][maxn];
signed main(){
	fl=freopen("subway.in","r",stdin);
	fl=freopen("subway.out","w",stdout);
	memset(disline,0x3f,sizeof(disline));
	status=scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (ll i=1;i<=m;i++){
		status=scanf("%lld",w+i);
	}
	for (ll i=1;i<=n;i++){
		status=scanf("%lld",alen+i);
		//astart[i]=apos+1;
		for (ll j=1;j<=alen[i];j++){
			ll aa,tt;
			status=scanf("%lld%lld",&aa,&tt);
			//++apos;
			//a[apos]=aa;
			//t[apos]=tt;
			interchange[aa].insert(interchange[aa].end(),{i,tt});
		}
	}
	for (ll i=1;i<=m;i++){
		for (auto p:interchange[i]){
			//fprintf(stderr,"(%d,%d)",p.first,p.second);
			for (auto p2:interchange[i]){
				disline[p.first][p2.first]=disline[p2.first][p.first]=p.second+p2.second;
			}
		}
		//fprintf(stderr,"\n");
	}//md^2
	for (ll k=1;k<=n;k++){
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=n;j++){
				if (i==j)disline[i][j]=0;
				if (disline[i][j]>disline[i][k]+disline[k][j]){
					disline[i][j]=disline[j][i]=disline[i][k]+disline[k][j];
				}
			}
		}
	}//n^3
	/*
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=n;j++){
			fprintf(stderr,"{%lld,%lld,%lld}",i,j,disline[i][j]);
		}
	}*/
	for (ll i=1;i<=q;i++){
		ll x,y;
		status=scanf("%lld%lld",&x,&y);
		ll precost=w[x]+w[y];
		ll mindisa=LLONG_MAX;
		for (auto p:interchange[x]){
			//fprintf(stderr,"(%d,%d)",p.first,p.second);
			for (auto p2:interchange[y]){
				ll change=disline[p.first][p2.first];
				ll inout=p.second+p2.second;
				ll disnow=change+inout;
				//fprintf(stderr,"[(%lld:%lld)+(%lld:%lld)=%lld]",p.first,p.second,p2.first,p2.second,inout);
				mindisa=min(mindisa,disnow);
			}
		}
		//fprintf(stderr,"(%lld,%lld)",precost,mindisa);
		printf("%lld\n",precost+mindisa);
	}//qd^2
	return 0;
}
/*
 * line1:1,2,4
 * line2:2,3,5
 */
