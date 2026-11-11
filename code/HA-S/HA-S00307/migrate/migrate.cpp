#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll C,T,n,d,a[N],ans,cnt;
void dfs(ll k,ll t){
	if(k==t){
		cnt++;
		return;
	}
	for(int i=k+1;i<=t;i++){
		if(a[t]-a[i]<=d)dfs(i,t);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",a[i]);
			for(int j=1;j<=i-3;j++){
				cnt=0;
				dfs(j,i);
				if(cnt==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

