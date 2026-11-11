#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[212345], b[212345], ans;
bool vis[212345];
void dfs(int k){
	if(k>m){
		ll now=b[1];
		for(int i=2; i<=m; i++){
			now&=b[i];
		}
		ans=max(ans, now);
		return;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			b[k]=a[i];
			vis[i]=true;
			dfs(k+1);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	if(n<=20){
		dfs(1);
		printf("%lld", ans);
	} else if(n<=2000){
		if(m==1){
			for(int i=1; i<=n; i++) ans=max(ans, a[i]);
			printf("%lld", ans);
		} else if(m==n){
			ans=a[1];
			for(int i=2; i<=n; i++) ans&=a[i];
			printf("%lld", ans);
		} else if(m==2){
			for(int i=1; i<=n; i++){
				for(int j=i+1; j<=n; j++){
					ll now=a[i]&a[j];
					ans=max(ans, now);
				}
			}
			printf("%lld", ans);
		}
	}
	return 0;
} 
