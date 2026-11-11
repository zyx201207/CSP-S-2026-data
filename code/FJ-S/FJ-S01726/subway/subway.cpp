#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500009],t[500009],a[500009],l,r,ans;
struct node{
	long long x,w;
};vector<node>v[500009];
void dfs(int u,long long p){
	if(u==r){
		ans=min(ans,p);
		return ;
	}if(a[u]<=p)return ;
	a[u]=p;
	for(int i=0;i<v[u].size();i++){
		dfs(v[u][i].x,p+v[u][i].w);
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		scanf("%lld",&w[i]);
	}for(int i=1;i<=n;i++){
		long long k;
//		cin>>k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
//			cin>>a[j]>>t[j];
			scanf("%lld%lld",&a[j],&t[j]);
			for(int g=1;g<j;g++){
				v[a[j]].push_back({a[g],t[g]+t[j]});
				v[a[g]].push_back({a[j],t[g]+t[j]});
			}
		}
	}while(q--){
//		cin>>l>>r;
		scanf("%lld%lld",&l,&r);
		ans=1e18;
		for(int i=1;i<=m;i++){
			a[i]=1e18;
		}dfs(l,0);
//		cout<<w[l]+ans+w[r]<<"\n";
		printf("%lld\n",w[l]+ans+w[r]);
	}
	return 0;
} 
