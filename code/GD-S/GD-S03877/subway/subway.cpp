#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define ll long long
int c,n,m,d,q,hd[507],e=0,k,inu,inv;
ll edg[507][507],it,ans1;
vector<pair<ll,int> > all1[500007];
void add(int u,int v,ll w){
	if(edg[u][v]!=-1)edg[u][v]=min(edg[u][v],w);
	else edg[u][v]=w;
	
	swap(u,v);
	
	if(edg[u][v]!=-1)edg[u][v]=min(edg[u][v],w);
	else edg[u][v]=w;
}
ll inw[500007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(hd,-1,sizeof(hd));
	memset(edg,-1,sizeof(edg));
	cin>>c>>n>>m>>d>>q;
	FOR(i,1,n+1){
		edg[i][i]=0;
	}
	
	FOR(i,1,m+1){
		cin>>inw[i];
	}
	FOR(i,1,n+1){
		cin>>k;
		FOR(j,0,k){
			cin>>inu>>it;
			FOR(k,0,all1[inu].size()){
				add(i,all1[inu][k].second,it+all1[inu][k].first);
			}
			all1[inu].push_back({it,i});
		}
	}
	FOR(k,1,n+1){
		FOR(i,1,n+1){
			if(i==k)continue;
			FOR(j,i+1,n+1){
				if(j==k)continue;
				if( (edg[k][i]!=-1) && (edg[k][j]!=-1) )add(i,j,edg[k][i]+edg[k][j]);
			}
		}
	}

	FOR(i,0,q){
		cin>>inu>>inv;
		ans1=-1;
		FOR(j,0,all1[inu].size()){
			FOR(k,0,all1[inv].size()){
				if(edg[all1[inu][j].second][all1[inv][k].second]!=-1){
					if(ans1!=-1)ans1=min(ans1,all1[inu][j].first+all1[inv][k].first+edg[all1[inu][j].second][all1[inv][k].second]); 
					else ans1=all1[inu][j].first+all1[inv][k].first+edg[all1[inu][j].second][all1[inv][k].second];
				}
			}
		}
		ans1+=inw[inu]+inw[inv];
		cout<<ans1<<endl;
	}
	return 0;
} 
