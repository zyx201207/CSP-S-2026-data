#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=0,q=0;
void dfs(int p,long long yu,int i){
	if(p==m){
		maxn=max(maxn,yu);
		return ;
	}if(i==n+1){
		return ;
	}if(yu==0){
		return;
	}
	if(i!=q){
		dfs(p+1,yu&a[i],i+1);
	}
	dfs(p,yu,i+1);
	
	
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		q=i;
		dfs(1,a[i],1);	
	}cout<<maxn;
	return 0;
}
