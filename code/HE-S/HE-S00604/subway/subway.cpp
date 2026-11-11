#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
ll c,n,m,d,q,ans,an;
vec<ll>w,x,y,k;
vec<vec<ll> >a,t;
vec<vec<ll>>e,r;
vec<bool>vis;
//void dfsa(ll g,ll b){
//	if(g==b){
//		ans=max(ans,an);
//		return;
//	}
//	for(ll i:a[b]){
//		if(vis[i])continue;
//		an+=t[b][i];
//		vis[i]=1;
//		dfsa(b,i);
//		vis[i]=0;
//		an-=t[b][i];
//	}
//}
void dfs(ll g,ll b){
	if(g==b){
		ans=max(ans,an);
	}
	for(ll i:e[g]){
		an+=r[g][i];
		vis[i]=1;
		dfs(i,b);
		vis[i]=0;
		an-=r[g][i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	w.resize(m+1);
	for(ll i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%lld",&w[i]);
	} 
	k.resize(n+3);
	a.resize(n+3);
	t.resize(n+3);/*
	if(7<=c&&11>=c){
		for(ll i=1;i<=n;i++){
			//a.resize(2);
			t.resize(2);
		}
	}*/
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		t[i].resize(k[i]);
		if(k[i]<=1)continue;
//		if(7<=c&&11>=c){/*
//			//a.resize(n+1,vec (2));
//			ll na,nb,ta,tb;
//			scanf("%lld%lld%lld%lld",&na,&ta,&nb,&tb);
//			//a[na][nb]=a[nb][na]=1;
//			a[na].push_back(nb);
//			//a[nb].push_back(na);
//			a[nb].push_back(na);
//	//
//			t[i][na]=w[na]+ta;
//			t[i][nb]=w[nb]+tb;
//			
//			*/
//			
//			ll na,nb,ta,tb;
//			cin>>na>>ta>>nb>>tb;
//			a[na].push_back(nb);
//			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
//			
//			a[nb].push_back(na);
//			t[i][na]=w[na]+ta;
//			t[i][nb]=w[nb]+tb;
//		}
		//else{
			a[i].resize(k[i]+1);
			t[i].resize(k[i]+1);
			for(ll j=1;j<=k[i];j++){
				ll p;
				scanf("%lld%lld",&a[i][j],&p);
				t[i][j]=w[a[i][j]]+p;
				
				//e[a[i][j]].push_back()
			}
			for(ll j=1;j<=k[i];j++){
				if(j!=k[i]){
					e[a[i][j]].push_back(a[i][j+1]);
					r[a[i][j]].push_back(t[i][j+1]);
					
				}
				if(j!=1){
					e[a[i][j]].push_back(a[i][j-1]);
					r[a[i][j]].push_back(t[i][j-1]);
				}
			} 
		//}
	}
	x.resize(q+1);
	y.resize(q+1);
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	vis.resize(m+1);
//	if(7<=c&&11>=c){//A
//		//dfsa
//		for(ll i=1;i<=q;i++){
//			vis[x[i]]=1;
//			dfsa(x[i],y[i]);
//			vis[x[i]]=0;
//			printf("%lld\n",ans);
//			ans=0;
//		}
//	}
//	if(12<=c&&19>=c){//B
//		
//	}

	
	for(ll i=1;i<=q;i++){
		an=0;
		ans=0;
		vis[x[i]]=1;
		dfs(x[i],y[i]);
		vis[x[i]]=0;
		printf("%lld",ans);
	}

	return 0;
}

