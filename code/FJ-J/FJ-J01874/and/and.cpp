#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],maxn=-1;
void dfs(long long x,long long y,long long z){
	if(x==m){
		maxn=max(maxn,z);
		return ;
	}else{
		for(int i=y;i<=n;i++){
			if(x==0)
				z=a[i];
			dfs(x+1,i+1,z&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,1,1);
	cout<<maxn;
	return 0;
}
