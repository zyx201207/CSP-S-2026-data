#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ans=0,n,m,a[200010];
void dfs(int cur,int cnt,int sum){
	if(cur==n+1){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(cur+1,cnt+1,sum&a[cur]);
	dfs(cur+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0,sum=0,amm=(1<<30)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		amm=a[i]&amm;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<amm;
		return 0;
	}
	dfs(1,0,(1<<30)-1);
	cout<<ans;
	return 0;
}
