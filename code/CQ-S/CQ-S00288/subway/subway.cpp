#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int N=20005;
ll c,n,m,d,z,tot,v1;
ll dis[N*20],sum;
struct node{
	ll a[21]={};
	ll w[21]={};
	int size;
}t[N];
ll w[N];
ll g[N];
vector<ll> v[N*20];
priority_queue<pa,vector<pa>,greater<pa> >q; 
bool sure[N];
ll find(ll x,ll y){
	sum=1e18;
	for(int i=1;i<=t[x].size;i++){
		int k=t[x].a[i];
		for(int j=1;j<=N*20-1;j++)
			dis[j]=1e18;
		memset(sure,0,sizeof(sure));
		dis[k]=t[x].w[i];
		q.push({dis[k],k});
		while(q.size()){
			ll o;
			o=q.top().second;
			q.pop();
			if(sure[o])	continue;
			sure[o]=1;
			for(int j=0;j<v[o].size();j++){
				int p=v[o][j];
				if(dis[p]>dis[o]+t[p/d].w[p%d]){
					dis[p]=dis[o]+t[p/d].w[p%d];
					q.push({dis[p],p});
				}
			}
		}		
		ll ans=1e18;
		for(int j=1;j<=t[y].size;j++){
			ans=min(ans,dis[t[y].a[j]]);
		}
		sum=min(sum,ans);
	}
	return sum+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>z;
	for(int i=1;i<=m;i++)
		cin>>w[i]; 
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		tot=0;
		for(int j=1;j<=k;j++){
			ll V,U;
			cin>>V>>U;
			t[V].size++;
			t[V].a[t[V].size]=V*d+t[V].size;
			t[V].w[t[V].size]=U;
			g[++tot]=V*d+t[V].size;
			if(t[V].size!=1){	
				for(int k=1;k<t[V].size;k++){
					v[t[V].a[k]].push_back(V*d+t[V].size);
					v[V*d+t[V].size].push_back(t[V].a[k]);
				}	
			}
		}
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
				if(i!=j){
					v[g[i]].push_back(g[j]);
					v[g[j]].push_back(g[i]);	
				}
	}
	for(int i=1;i<=z;i++){
		ll l,r;
		cin>>l>>r;
		cout<<find(l,r)<<'\n'; 
	}
	
	return 0;
}
