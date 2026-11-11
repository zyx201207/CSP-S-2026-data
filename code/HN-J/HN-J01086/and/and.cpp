#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200];
int ans;
void dfs(int u,int cnt,int sum){
	if (cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if (n-u+1<m-cnt) return ;
	if (sum==-1) dfs(u+1,cnt+1,a[u]);
	else dfs(u+1,cnt+1,sum&a[u]);
	dfs(u+1,cnt,sum);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (m==n-1){
		int q=a[1],p=a[n];
		for (int i=2;i<n;i++){
			q&=a[i];
			p&=a[i];
		}
		cout<<max(p,q);
	}
	else if (m==n){
		int q=a[1];
		for (int i=2;i<=n;i++){
			q&=a[i];
		}
		cout<<q;
	}
	else if (m==1){
		cout<<a[n];
	}
	else{
		dfs(1,0,-1);
		cout<<ans;
	}
	return 0;
}
