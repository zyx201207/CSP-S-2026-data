#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4010,M=1e6+10;
ll c,T,n,k,x,y,d[N][N],p[N];
vector<ll>line[M];
void init(){
	for(int i=1;i<=n;i++){
		line[i].clear();
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=0;
			}
		}
	}
}
void dfs(ll x){
	p[x]=0;
	for(auto to:line[x]){
		if(p[to])dfs(to);
	}
}
bool check_dis(ll x){
	ll res=0;
	for(int bit=1;bit<=n;bit++){
		if((x>>(bit-1))&1){
			res++;
			p[bit]=1;
		}
		else p[bit]=0;
	}
	ll lian=0;
	for(int i=1;i<=n;i++){
		if(p[i]){
			lian++;
			dfs(i);
		}
	}
	if(res==k&&lian<=2)return 1;
	return 0;
}
void get_dis(ll root,ll x,ll fa){
	if(!fa)d[root][x]=0;
	else d[root][x]=d[root][fa]+1;
	for(auto to:line[x]){
		if(to==fa)continue;
		get_dis(root,to,x);
	}
}
bool check(ll t){
	ll m=(n-1)/2;
	ll l=t-1,r=l+k/2;
	ll mid=r+t-1;
	ll x=mid+t-1,y=x+(k+1)/2;
	return (y+t-1)>=m;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			line[x].push_back(y);
			line[y].push_back(x);
		}
		if(n<=10){
			ll ans=1e18;
			for(int i=1;i<=n;i++){
				get_dis(i,i,0); 
			}
			for(int i=1;i<(1<<n);i++){
				if(check_dis(i)){
					ll sum=0;
					for(int bit=1;bit<=n;bit++){
						ll dis=1e18;
						for(int p=1;p<=n;p++){
							if((i>>(p-1))&1)dis=min(dis,d[p][bit]);
						}
						sum=max(sum,dis);
					}
					ans=min(ans,sum);
				}
			}
			printf("%lld\n",ans);
			init();
		}
		else{
			if(n==k){
				puts("0");
				init();
				continue;
			}
			ll l=1,r=n,mid=0,ans=0;
			while(l<=r){
				ll mid=(l+r)>>1;
				if(check(mid)){
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			printf("%lld\n",ans);
			init();
		}
	}
	return 0;
}
