#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
long long ans_this;
bool vis[100005]; 
void dfs(long long x[],long long dep){
	if(dep==m){
		ans=max(ans,ans_this);
		return;
	}else{
		for(long long i=1;i<=n;i++){
			if(vis[i]) continue;
			long long tmp=ans_this;
			if(dep=0) ans_this=x[i];
			else ans_this|=x[i];
			vis[i]=1;
			dfs(x,dep+1);
			vis[i]=0;
			ans_this=tmp;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+10];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(a,0);
	cout<<ans<<endl;
	return 0;
} 
