#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	struct line{
		ll id,t,pr,nx;
	}cnt2[30];
	ll w,cnt1,id3[30];
}a[500010];
ll c,n,m,d,q,k,rx,ry,id1,tt,id2;
void dfs(ll x,ll co,ll ii){
	if(x==ry){
		if(c!=0)c=min(c,co+a[x].cnt2[ii].t);
		else c=co+a[x].cnt2[ii].t;
		return;
	}
	if(co>c&&c!=0)return;
	vis[x]=1;
	for(int i=1;i<=a[x].cnt1;i++){
		if(vis[a[x].cnt2[a[x].id3[i]].pr]==0){
			if(a[x].cnt2[a[x].id3[i]].id!=ii){
				dfs(i,co+=(),ju[x][i].id1);
			}else dfs(i,co,ju[x][i].id1);
		}
	}
	vis[x]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&a[i].w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&id1,&tt);
			a[id1].cnt1++,a[id1].id3[a[id1].cnt1]=i,a[id1].cnt2[i].id=id1,a[id1].cnt2[a[id1].cnt1].t=tt,a[id2].cnt2[a[id2].cnt1].nx=id1,a[id1].cnt2[a[id1].cnt1].pr=id2;
			id2=id1;
		}
	}
	for(int i=1;i<=q;i++){
		c=0;
		scanf("%lld%lld",&rx,&ry);
		dfs(rx,a[rx].w,0);
		cout<<c+a[ry].w<<endl;
	}
	return 0;
}
