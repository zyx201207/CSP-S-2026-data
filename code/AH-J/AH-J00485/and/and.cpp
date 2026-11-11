#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200010];
ll ans1;
void dfs(int now,int cnt,ll ans){
	if(now>n||(now==n&&cnt<m))return;
	if(cnt==m){
		ans1=max(ans1,ans);
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,cnt+1,ans&a[i]);
		dfs(i+1,cnt,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(a[i],maxx);
	}
	if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}else if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,ll(a[i]));
	}
	printf("%lld",ans1);
	return 0;
}
