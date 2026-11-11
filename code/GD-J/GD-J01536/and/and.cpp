#include<bits/stdc++.h>
using namespace std;
const int Q=1e5*2+5;
int n,m;
long long a[Q];
long long ans,cnt;
void dfs(int x,int y,int z){
	if(y>=m){
		if(ans<cnt) ans=cnt;
		z=z|a[x];
	    return;
	} 
	z=z&a[x];
	for(int i=x;i<=n;i++) dfs(i,y+1,z);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		dfs(j,1,a[j]);
	}
	cout<<ans;
	return 0;
}


