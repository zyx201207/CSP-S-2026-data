#include<bits/stdc++.h>
#define l long long
using namespace std;
int n,m;
l a[200020],dp[30][30],ans=-1;
void dfs(l x,l s,l maxn){
	if(x==n){
		if(s==m){
			ans=max(ans,maxn);
		}
		return;
	}
	if(s==0){
		dfs(x+1,1,a[x+1]);
		dfs(x+1,0,0);
	}else{
		dfs(x+1,s+1,maxn&a[x+1]);
		dfs(x+1,s,maxn);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(m==1){
		sort(a+1,a+n+1);
		printf("%lld",a[n]);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
	}else if(m==n){
		l s=a[1];
		for(int i=2;i<=n;i++)s=s&a[i];
		printf("%lld",s);
	}else{
		dfs(0,0,0);
		printf("%lld",ans);
	}
	return 0;
}
