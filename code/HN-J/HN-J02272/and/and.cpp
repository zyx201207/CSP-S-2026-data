#include<bits/stdc++.h>
using namespace std;
int n,m;
long long x,ans,a[200010];
void dfs(long long x,int ii,int d){
	if(d==0){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i=ii)continue;
		dfs(x&a[i],i,d-1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],i,m-1);
	}
	cout<<ans;
	return 0;
}
