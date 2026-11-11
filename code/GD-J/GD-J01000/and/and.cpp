#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],ans;
int n,m;
bool vis[N];
void dfs(int dep,ll now){
	if(dep==m){
		ans=max(ans,now);
		return ;
	}
	if(now<ans){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		dfs(dep+1,now&a[i]);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==n-1){
		ans=a[2];
		for(int i=3;i<=n;i++){
			ans&=a[i];
		}
		for(int j=2;j<=n;j++){
			ll now=a[j-1];
			for(int i=1;i<=n;i++){
				if(i==j-1||i==j){
					continue;
				}
				now&=a[i];
			}
			ans=max(ans,now);
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	if(m>2000){
		sort(a+1,a+n+1,greater<ll>());
	    printf("%lld",a[m]);
	    return 0;
	} 
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	printf("%lld",ans);
	return 0;
} 
