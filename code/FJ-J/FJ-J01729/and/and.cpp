#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],maxa,ans;
void dfs(long long sdf,long long jg,long long xb){
	if(sdf>m){
		ans=max(ans,jg);
		return;
	}
	if(xb>n){
		return;
	}
	for(long long i=xb;i<=n;i++){
		dfs(sdf+1,jg&a[i],i);
		dfs(sdf+1,jg,i);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	else{
		for(long long i=1;i<=n;i++){
			dfs(1,a[i],i);
		}
		cout<<ans;
	}
	return 0;
}