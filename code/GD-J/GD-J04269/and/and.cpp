#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1e9;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long u,long long v,long long sum){
	if(v==m){
		ans=max(ans,sum);
		return;
	}
	if(u>n)return;
	if(v==0){
		dfs(u+1,v+1,a[u]);
		dfs(u+1,v,sum);
	}else{
		dfs(u+1,v+1,sum&a[u]);
		dfs(u+1,v,sum);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
