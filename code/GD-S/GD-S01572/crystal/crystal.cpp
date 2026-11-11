#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m,ans;
void dfs(int cnt){
	if(cnt>=m){
		map<long long,int> mp;
		long long t=0;
		for(int i=1;i<=n;i++){
			t=max(t,1ll*++mp[a[i]]);
		}
		ans=max(ans,t);
		return ;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(cnt+1);
		a[i]--;
	}
}
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	dfs(0);
	printf("%lld",ans);
	return 0;
} 
