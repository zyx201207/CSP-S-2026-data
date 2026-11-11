#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],maxx=INT_MIN;
void dfs(int x,int y,int z){
	if(x>n+1) 
	{
		if(z>maxx) maxx=z;
		return ;
	}
	if(y>=m){
		if(z>maxx) maxx=z;
		return ;	
	}
	if(n-x+1+y<m) return ;
	dfs(x+1,y+1,z&a[x]);
	dfs(x+1,y,z);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,2e31-1);
	cout<<maxx;
	return 0;
}
