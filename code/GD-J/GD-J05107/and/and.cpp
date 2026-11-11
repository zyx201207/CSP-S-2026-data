#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100010];
long long MAX;
void dfs(long long idx,long long cnt,long long num){
	if(cnt==m){
		MAX=max(MAX,num);
		return;
	}
	if(idx>n){
		return;
	}
	if(n-idx<m-cnt){
		return;
	}
	if(num==0){
		dfs(idx+1,0,0);
		dfs(idx+1,cnt+1,a[idx]);
	}
	else{
		dfs(idx+1,cnt,num);
		dfs(idx+1,cnt+1,(num and a[idx]) );
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<MAX;
	return 0;
}
