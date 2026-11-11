#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200001],maxn=0;
long long g[200001],k[200001];

void dfs(int x){
	if(x>m){
		long long j=g[1];
		for(int i=2;i<x;i++) j&=g[i];
		if(j>maxn) maxn=j;
	}
	for(int i=1;i<=n;i++){
		if(k[i]==0){
			g[x]=a[i];
			k[i]=1;
			dfs(x+1);
			k[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
