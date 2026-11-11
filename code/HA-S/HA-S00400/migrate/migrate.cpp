#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define wep(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)
#define tep(a,b) for(auto &(a):(b))
using namespace std;
const ll N=5e5+5;
ll a[N];
ll num=0;
ll n,d,cnt;
void dfs(ll x,ll y,ll sum){
	if(sum>cnt)
		return ;
	if(x==y){
		num++;
		return ;
	}
	rep(i,x+1,y){
		if(a[i]-a[x]<=d){
			dfs(i,y,sum+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll CCF_is_shu_jv_shan_chu,T,ans=0;
	cin>>CCF_is_shu_jv_shan_chu>>T;
	while(T--){
		ans=0;
		n,d;
		cin>>n>>d;
		rep(i,1,n){
			cin>>a[i];
		}
		rep(i,1,n){
			rep(l,i+1,n){
				num=0;
				cnt=0;
				ll now=i;
				bool flag=1;
				while(now<l){
					ll x=now;
					rep(k,now+1,l){
						if(a[k]-a[now]>d){
							break;
						}
						x=k;
					}
					if(x==now){
						flag=0;
						break;
					}
					now=x;
					cnt++;
				}
				if(!flag)
					continue;
				dfs(i,l,0);
				if(num==2){
					ans++;
				}
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
