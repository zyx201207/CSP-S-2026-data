#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=1e9+10;

int n,m,a[N],xz[N];
long long ans=0;

void dfs(int u,int cur){
	if(u>m){
		long long t=a[xz[1]];
		for(int i=1;i<=m;i++){
			t=t&a[xz[i]];
		}
		ans=max(ans,t);
	}
	if(cur>n)return ;
	xz[u]=cur;
	dfs(u+1,cur+1);
	xz[u]=0;
	dfs(u,cur+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<ans;
	return 0;
}
