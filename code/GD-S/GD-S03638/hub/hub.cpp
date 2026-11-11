#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll c,t,n,k,dd[15],db,bj[15];
struct edge{
	ll q,z,xg;
}ed[205];
void fjq(ll q,ll z){
	ed[++db]={q,z,dd[q]},dd[q]=db;
}
ll dfs(ll root,ll fa,ll dj){
	if(bj[root])return dj;
	ll re=1145141919810;
	for(ll i=dd[root];i;i=ed[i].xg){
		ll to=ed[i].z;
		if(to==fa)continue;
		re=min(re,dfs(to,root,dj+1));
	}
	return re;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
//		cout<<"F"<<n<<' '<<k<<endl;
		ll aa,bb;
		db=0;
		for(ll i=1;i<=n;i++){
			dd[i]=0;
		}
		for(ll i=1;i<n;i++){
			scanf("%lld%lld",&aa,&bb);
			fjq(aa,bb),fjq(bb,aa);
		}
		ll ans=1145141919810;
		for(ll ii=1;ii<(1<<n);ii++){
			ll gs=0,ti=ii;
			while(ti){
				gs++;
				ti^=(ti&-ti);
			}
//			cout<<ii<<' '<<gs<<' '<<k<<"F"<<endl;
			if(gs!=k)continue;
			ll da=0;
			for(ll j=1;j<=n;j++){
				if(ii&(1<<(j-1))){
					bj[j]=1;
//					cout<<j<<endl;
				}
				else bj[j]=0;
			}
			ll zs=gs*2;
			for(ll i=1;i<=db;i++){
				if(bj[ed[i].q]==1&&bj[ed[i].z]==1){
					zs--;
				}
			}
			if(zs>4){
				continue;
			}
			for(ll j=1;j<=n;j++){
				ll dz=dfs(j,0,0);
//				cout<<j<<' '<<dz<<endl;
				da=max(da,dz);
			}
//			cout<<ii<<' '<<gs<<":"<<da<<endl;
			ans=min(ans,da);
		} 
		printf("%lld\n",ans);
	}
	return 0;
}

// 15
