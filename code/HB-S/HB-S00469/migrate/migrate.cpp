#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int c,t,n,d;
int x[N],minn,ans,ANS;
void dfs(int s,int st,int e){
	if(st>minn) return;
	if(s>e) return;
	if(s==e){
		if(st<minn){
			minn=st;
			ans=1;
		}else ans++;
		return;
	}int maxx=upper_bound(x+1,x+1+n,x[s]+d)-x-1;
	maxx=min(maxx,e);
	for(int next=maxx;next>s;--next){
		if(x[next]-x[s]<=d) dfs(next,st+1,e);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=0;
				minn=INT_MAX;
				dfs(i,0,j);
				if(ans==2){
					ANS++;
				}			
			}
		}printf("%lld\n",ANS);
		ANS=0;
	}
	
	return 0;
}
