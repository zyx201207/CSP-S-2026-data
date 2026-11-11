#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>
#define ll long long

ll n,m,c,q,d,w[500010],k[510],hc[510][510],dis[510][510],maxc=4557430888798830399;
vector<pll> a[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			a[x].push_back(make_pair(i,y));
		}
	}
	memset(hc,0x3f,sizeof(hc));
	for(int i=1;i<=m;i++){
		ll lo=a[i].size(),x=0;
		while(x<lo){
			ll num=a[i][x].first,ti=a[i][x].second; 
			for(int j=0;j<x;j++){
				ll t1=a[i][j].first,t2=a[i][j].second;
				hc[num][t1]=min(hc[num][t1],t2+ti);
				hc[t1][num]=min(hc[t1][num],t2+ti);
			}
			x++;
		}
	} 
	for(int i=1;i<=n;i++){
		hc[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				hc[i][j]=min(hc[i][k]+hc[j][k],hc[i][j]);
				hc[j][i]=hc[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=1e18+10;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				ans=min(ans,w[x]+w[y]+a[x][j].second+a[y][k].second+hc[a[x][j].first][a[y][k].first]);
			}
		}
		cout<<ans<<endl;
	}
}
