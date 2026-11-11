#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500010;
const ll M=510;
const ll Max=1e9+7;
struct node{
	ll p;
	ll d;
}g[N][22];
ll c,n,m,d,q;
ll w[N],k[M],t,a;
ll l[N],mp[M][M];
ll x,y,mn,l1,l2;
ll min(ll f,ll o){
	if(f<o)return f;
	return o;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(l,0,sizeof(l));
	memset(mp,Max,sizeof(mp));
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a>>t;
			g[a][++l[a]].d =t;
			g[a][l[a]].p =i;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=l[i];j++){
			for(ll r=1;r<j;r++){
				ll p1=g[i][j].p ,p2=g[i][r].p ;
				ll L=mp[p1][p2];
				mp[p1][p2]=min(L,g[i][j].d +g[i][r].d);
				mp[p2][p1]=min(L,g[i][j].d +g[i][r].d);
			}
		}
	}
	for(ll i=1;i<=n;i++)
		mp[i][i]=0;	
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		if(mp[i][j]>=Max)
	//			cout<<-1<<' ';
	//		else
	//			cout<<mp[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	while(q--){
		cin>>x>>y;
		mn=Max,l1=1,l2=1;
		for(ll i=1;i<=l[x];i++){
			for(ll j=1;j<=l[y];j++){
				ll p1=g[x][i].p ,p2=g[y][j].p ;
				if(mp[p1][p2]<mn){
					mn=mp[p1][p2];
					l1=i,l2=j;
				}
			}
		}
		mn+=w[x]+w[y]+g[x][l1].d +g[y][l2].d ;
		cout<<mn<<endl;
	}
	return 0;
}
