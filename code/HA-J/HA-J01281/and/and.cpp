#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx;
void dfs(int x,long long s,int k){
	if(x==m){
		maxx=max(maxx,s);
		return ;
	}
	if(s==0){
		return ;
	}
	for(int i=k;i<=n;i++){
		dfs(x+1,s&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,2147483647,1);
	cout<<maxx;
	return 0;
}
