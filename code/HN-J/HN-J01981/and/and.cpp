#include<bits/stdc++.h>
using namespace std;

long long a[100000]={},xuanze[30001]={};
long long n,m,maxn=-1;
void dfs(long long x,long long xz){
	if(xz==m){
		long long yu=xuanze[1];
		for(int i=2;i<=m;i++){
			yu=yu&xuanze[i];
		}
		maxn=max(maxn,yu);
		return ;
	}
	for(long long v=x+1;v<=n;v++){
		xuanze[xz+1]=a[v];
		dfs(v,xz+1);
		xuanze[xz+1]==0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
