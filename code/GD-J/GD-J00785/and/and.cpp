#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],ma;
void dfs(int x,int sum,int y){
	if(x==n+1 && y!=m) return;
	if(y==m){
		ma=max(ma,sum);
		return;
	}dfs(x+1,sum&a[x],y+1);
	dfs(x+1,sum,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,(1<<31)-1,0);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
