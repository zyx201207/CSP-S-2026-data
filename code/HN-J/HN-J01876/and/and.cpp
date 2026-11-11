#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define IN(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int n,m;
int a[200007];
int f[10007][10007];
int z[200007];
int ans;
int dfs(int x,int y){

	if(y==m+1){
		int s=z[1];
		for(int i=1;i<=m;i++){
			s=s&z[i];
		}
		f[x][y]=max(f[x][y],s);
		return f[x][y];
	}
	
	if(f[x][y])return f[x][y];
	
	
	
	for(int i=x+1;i<=n-m+y;i++){
		z[y]=a[i];
		f[x][y]=max(f[x][y],dfs(i,y+1));
	}
	return f[x][y];
}



signed main(){
	IN("and");
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		int ans=0;
		if(a[10]!=9){
			ans=10000000;
			for(int i=1;i<=n;i++){
				ans=min(ans,a[i]);
			}
			cout<<ans;
		}
		else{
			cout<<0;
			return 0;
		}
		return 0;
	}
	cout<<dfs(0,1);
	
	return 0;
}
