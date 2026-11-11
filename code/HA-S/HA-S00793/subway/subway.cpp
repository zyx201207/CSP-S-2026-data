#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxm 500010
#define maxn 2010 

ll c,n,m,d,q,qs,qe,tot=1;
ll mp[maxn][maxn],a[maxm];

ll shu[maxm][5];

ll lmp[maxn][maxn]; 

struct ken{
	ll pos,cost; 
}line[maxm];

struct ken2{
	ll id,cost;
}zhu[maxm][23];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	memset(lmp,0x3f,sizeof(lmp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
//	if(0){
//		for(int i=1;i<=n;i++){
//			ll S=tot,cur;
//			cin>>cur;
//			ll E=cur+S-1;
//			for(;tot<=E;tot++) cin>>line[tot].pos>>line[tot].cost;
//			for(int l=S;l<=E-1;l++){
//				for(int r=l+1;r<=E;r++){
//					ll pl=line[l].pos,pr=line[r].pos;
//					ll Cost=line[l].cost+line[r].cost;
//					mp[pl][pr]=min(mp[pl][pr],Cost);
//					mp[pr][pl]=min(mp[pr][pl],Cost);
//				}
//			} 
//		}
//		for(int i=1;i<=m;i++) mp[i][i]=0;
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				for(int k=1;k<=m;k++){
//					mp[j][k]=min(mp[j][k],mp[j][i]+mp[i][k]);
//				}
//			}
//		}
//		for(int i=1;i<=q;i++){
//			cin>>qs>>qe;
//			cout<<mp[qs][qe]+a[qs]+a[qe]<<'\n';
//		}
//		return 0;
//	} 
//	if(c==20||c==21){
//		ll Cost;
//		for(int i=1;i<=n;i++){
//			ll S=tot,cur;
//			cin>>cur;
//			ll E=cur+S-1;
//			for(;tot<=E;tot++){
//				cin>>line[tot].pos>>line[tot].cost;
//				shu[line[tot].pos][i]=1;
//			}
//		}
//		Cost=line[1].cost*2;
//		for(int i=1;i<=q;i++){
//			cin>>qs>>qe;
//			ll flag=0;
//			if(shu[qs][1]==1&&shu[qe][1]==1) flag=1;
//			if(shu[qs][2]==1&&shu[qe][2]==1) flag=1;
//			ll ans=0;
//			if(!flag) ans+=Cost;
//			cout<<a[qs]+a[qe]+ans<<'\n'; 
//		}
//		return 0;
//	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll p,C;
			cin>>p>>C;
			zhu[p][++zhu[p][0].id].id=i;
			zhu[p][zhu[p][0].id].cost=C;
		}
	}
	for(int i=1;i<=m;i++){
		ll D=zhu[i][0].id;
		for(int l=1;l<=D-1;l++){
			for(int r=l+1;r<=D;r++){
				ll lp=zhu[i][l].id,rp=zhu[i][r].id;
				ll Cost=zhu[i][l].cost+zhu[i][r].cost;
				lmp[lp][rp]=min(lmp[lp][rp],Cost);
				lmp[rp][lp]=min(lmp[rp][lp],Cost);
			}
		}
	}
	for(int i=1;i<=n;i++) lmp[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				lmp[j][k]=min(lmp[j][k],lmp[j][i]+lmp[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs>>qe;
		ll cur=1e14,ds=zhu[qs][0].id,de=zhu[qe][0].id;
		for(int l=1;l<=ds;l++){
			for(int r=1;r<=de;r++){
				ll lp=zhu[qs][l].id,rp=zhu[qe][r].id;
				ll Cost=zhu[qs][l].cost+zhu[qe][r].cost;
				Cost+=lmp[lp][rp];
				cur=min(cur,Cost);
			}
		}
		cout<<cur+a[qs]+a[qe]<<'\n';
	}
	return 0;
}


