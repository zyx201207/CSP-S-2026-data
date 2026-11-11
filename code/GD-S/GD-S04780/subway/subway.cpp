#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10,M=1e3+10;
ll c,n,m,d,q,w[N],k[N],h[N],idx,ff[M],x,y,f[M][M],tmp;
map<pair<ll,ll>,bool>g,st; 
vector<ll>t[M],_i[M],a[M],_j[M];
pair<ll,ll>aa[M];
map<pair<ll,ll>,ll>lans;
void Add(ll u,ll v,ll w){
	f[u][v]=f[v][u]=min(f[u][v],w);
}
void dfs(ll x){
	
}
void Floyd(){
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
	
}ll check(ll i,ll x){
	if(aa[i].first==x)
		return 1;
	if(aa[i].second==x)
		return 2;
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	if(c<7||c>11){
		memset(f,0x3f,sizeof f);
		//printf("f:\n");
		
		for(ll i=1;i<=n;i++){
			scanf("%lld",k+i);
			for(ll j=1;j<=2*k[i];j++){
				scanf("%lld",&tmp);
				if(j==1)
					ff[i]=tmp;
				if(j%2==1){
					g[{ff[i],tmp}]=1;
					_i[tmp].push_back(i);
					a[i].push_back(tmp);
					_j[tmp].push_back(j);
				}if(j%2==0){
					t[i].push_back(tmp); 
				}
			}
		}for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				for(ll k=0;k<a[i].size();k++)
					for(ll l=0;l<a[j].size();l++){
						if(a[i][k]==a[j][l]){
						//	printf("t[%lld][%lld]=%lld\nt[%lld][%lld]=%lld\n\n",i,k,t[i][k],j,l,t[j][l]);
							f[i][j]=min(f[i][j],t[i][k]+t[j][l]);
						}
							
					}
			} 
		
			
		while(q--){
			
			ll ans=1e16;
			scanf("%lld%lld",&x,&y);
			if(lans[{x,y}]){
				printf("%lld\n",lans[{x,y}]); 
				continue;
			}
				
			//dfs(x,y);
			
			for(ll i=0;i<_i[x].size();i++){
				for(ll j=0;j<_i[y].size();j++){
					ll ix=_i[x][i],iy=_i[y][j];
					ans=min(ans,f[ix][iy]+t[ix][_j[x][i]]+t[iy][_j[y][i]]);
				}
			}ans=ans+w[x]+w[y];
			lans[{x,y}]=ans+w[x]+w[y];
			printf("%lld\n",ans);
		}
		}
	if(7<=c&&c<=11){
		memset(f,0x3f,sizeof f);
		for(ll i=1;i<=n;i++)
			f[i][i]=0ll;
		for(ll i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(ll j=1;j<=2*k[i];j++){
			scanf("%lld",&tmp);
			if(j==1){
				aa[i].first=tmp;
				st[{tmp,i}]=1;
			}else if(j==3){
				aa[i].second=tmp;
				st[{tmp,i}]=1;
			}else{
				t[i].push_back(tmp); 
			}
		}
		}
	//printf("fsa\n");
		for(ll i=1;i<n;i++)
			for(ll j=i+1;j<=n;j++){
				if(aa[i].first==aa[j].first){
					Add(i,j,t[i][0]+t[j][0]); 
					Add(j,i,t[i][0]+t[j][0]); 
				}if(aa[i].first==aa[j].second){
					Add(i,j,t[i][0]+t[j][1]); 
					Add(j,i,t[i][0]+t[j][1]); 
				}if(aa[i].second==aa[j].first){
					Add(i,j,t[i][1]+t[j][0]); 
					Add(j,i,t[i][1]+t[j][0]); 
				}if(aa[i].second==aa[j].second){
					Add(i,j,t[i][1]+t[j][1]); 
					Add(j,i,t[i][1]+t[j][1]); 
				}
			}
		Floyd();
	//	printf("trg\n");
		while(q--){
			ll ans=1e16;
			scanf("%lld%lld",&x,&y);
			if(lans[{x,y}]){
				printf("%lld\n",lans[{x,y}]); 
				continue;
			}
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					if(check(i,x)&&check(j,y)){
						ll wt,wtw;
						if(check(i,x)==1)
							wt=t[i][0];
						else
							wt=t[i][1];
						if(check(j,y)==1)
							wtw=t[j][0];
						else
							wtw=t[j][1];
						
						ans=min(ans,f[i][j]+wtw+wt);
						
					}
				}
			}printf("%lld\n",ans+w[x]+w[y]);
			lans[{x,y}]=ans+w[x]+w[y];
			//printf("ars\n");
		}return 0;
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}

