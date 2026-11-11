#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500007];
ll coll[500007][27],coll_v[500007][27];
ll edg[507][507];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll p,v;
			cin>>p>>v;
			coll[p][0]++;
			coll[p][coll[p][0]]=i;
			coll_v[p][coll[p][0]]=v;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=coll[i][0];j++){
			for(int k=1;k<=coll[i][0];k++){
				if(j==k) continue;
				if(!edg[coll[i][j]][coll[i][k]]) edg[coll[i][j]][coll[i][k]]=coll_v[i][j]+coll_v[i][k];
				else edg[coll[i][j]][coll[i][k]]=min(coll_v[i][j]+coll_v[i][k],edg[coll[i][j]][coll[i][k]]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j==k) continue;
				if(i==j||i==k) continue;
				if(edg[j][i]&&edg[i][k]){
					if(!edg[j][k]) edg[j][k]=edg[j][i]+edg[i][k];
					else edg[j][k]=min(edg[j][i]+edg[i][k],edg[j][k]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		for(int j=1;j<=coll[x][0];j++){
			for(int k=1;k<=coll[y][0];k++){
				ll a=coll[x][j];
				ll b=coll[y][k];
				if(!ans) ans=edg[a][b]+coll_v[x][j]+coll_v[y][k];
				else ans=min(ans,edg[a][b]+coll_v[x][j]+coll_v[y][k]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
