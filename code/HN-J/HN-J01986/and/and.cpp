#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int dep,int sum,int summ){
	if(sum<ans||dep>n)
		return ;
	if(summ==m){
		ans=max(ans,sum);
		return ;
	}
	dfs(dep+1,sum,summ);
	dfs(dep+1,sum&a[dep],summ+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	dfs(2,a[1],1);
	cout<<ans;
	return 0;
}
