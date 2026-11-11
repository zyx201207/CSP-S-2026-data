#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10;
ll n,m,a[N],maxx;
void dfs(int u,int num,int sum){
	if(u>n){
		if(num==m){
			maxx=max(maxx,sum);
		}
		return;
	}
	dfs(u+1,num,sum);
	if(num<m){
		if(num==0)dfs(u+1,num+1,a[u]);
		else dfs(u+1,num+1,sum&a[u]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxx<<"\n"; 
	return 0;
}
