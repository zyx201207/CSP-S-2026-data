#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e6+10;
struct Edge{
	ll to,next;
}e[N];
ll c,t,n,d,x[N],h[N],idx,res,dis,answer;
void add(ll u,ll v){
	e[++idx].to=v;
	e[idx].next=h[u];
	h[u]=idx;
}void dfs(ll u,ll v,ll ddis){
	//printf("dfs(%lld,%lld)\n",u,v);
	if(ddis>dis) return;
	if(u==v) {
		if(ddis<dis){
			dis=ddis;
			res=1;
		}else if(ddis==dis){
			res++;
		}
		return;
	}
	for(ll i=h[u];i;i=e[i].next){
		ll to=e[i].to;
	//	printf("%lld->%lld\n",u,to);
		dfs(to,v,ddis+1);
	}
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=10){
		while(t--){
			ll ans=0ll;
			for(ll i=1;i<=idx+1;i++)
				h[i]=0;
			idx=0;
			scanf("%lld%lld",&n,&d);
			for(ll i=1;i<=n;i++){
				scanf("%lld",x+i);
			}for(ll i=1;i<n;i++)
				for(ll j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						add(i,j);
						//add(j,i);
					}
				}
			for(ll u=1;u<n;u++){
				for(ll v=u+1;v<=n;v++){
					res=0ll;
					dis=0x3fffffff;
				//	printf("\n----------------\n");
					dfs(u,v,0);
					//printf("\n----------------\n");
					if(res==2) ans++;
				}
					
			}
			printf("%lld\n",ans); 
		}
	}
	if(c==11||c==12){
		while(t--){
			ll ans=0ll;
			for(ll i=1;i<=idx+1;i++)
				h[i]=0;
			idx=0;
			scanf("%lld%lld",&n,&d);
			for(ll i=1;i<=n;i++){
				scanf("%lld",x+i);
			}ll i=1;
				for(ll j=i+1;j<=n;j++){
					if(x[j]-x[1]<=d){
						add(i,j);
						//add(j,i);
					}
				}
				ll u=1;
				for(ll v=u+1;v<=n;v++){
					ans=0ll;
					res=0ll;
					dis=0x3fffffff;
				//	printf("\n----------------\n");
					dfs(u,v,0);
					//printf("\n----------------\n");
					if(res==2) ans++;
					answer+=(n-v+1)*ans;
				}
					
			
			printf("%lld\n",answer); 
		}
	}
	if(c==13||c==14){
		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

