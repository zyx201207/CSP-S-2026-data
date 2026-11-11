#include<bits/stdc++.h>
using namespace std;
int mark[200000],c[200000],a[200000];
int n,m;
int maxn=-1;
void dfs(int x){
	if(x==m+1){
		int sum=c[1];
		for(int i=2;i<=x-1;i++){
			sum&=c[i];
		}
		maxn=max(sum,maxn);
	}
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			mark[i]=1;
			c[x]=a[i];
			dfs(x+1);
			mark[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<maxn;
}
