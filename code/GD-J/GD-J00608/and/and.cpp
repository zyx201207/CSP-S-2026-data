#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,andd,mx_sum;
int a[N];
void dfs(int k,int u,int ans,int flag){
	if(k==n+1){
		if(u==m) mx_sum=max(ans,mx_sum);
		return;
	}
	if(flag==0){
		dfs(k+1,u,ans,flag);
		dfs(k+1,u+1,a[k],1);
	}else{
		dfs(k+1,u,ans,flag);
		dfs(k+1,u+1,ans&a[k],1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<mx_sum;
	return 0;
}

