#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+10;
ll w[N],h[N];
bool vis[N];
struct node{
	ll id,v;
}ek[210];
struct edge{
	ll y,z;
};
vector<edge> a[N];
ll op,n,m,d,q;
ll res=0;
void dfs(int l,int r,ll sum){
	if(l==r){
		res=min(sum,res);
		return;
	}
	vis[l]=1;
	for(auto i:a[l]){
		if(!vis[i.y])
		dfs(i.y,r,sum+i.z);
	}
	vis[l]=0;
	return;
}
void work_A(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int k=1;k<=n;k++){
		int p;
		cin>>p;
		for(int i=1;i<=p;i++)cin>>ek[i].id>>ek[i].v;
		for(int i=1;i<=p;i++){
			for(int j=1;j<=i;j++){
				if(i==j)continue;
				ll x=ek[i].id,y=ek[j].id;
				ll z=ek[i].v+ek[j].v;
				a[x].push_back({y,z});
				a[y].push_back({x,z});
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		res=2e18+10;
		ll l,r;
		cin>>l>>r;
		ll ans=0;
		ans+=w[l]+w[r];
		dfs(l,r,0);
		ans+=res;
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op;
	work_A();
	return 0;
}
