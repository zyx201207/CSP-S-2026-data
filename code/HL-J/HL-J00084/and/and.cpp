#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ma;
void dfs(int u,int step,int cnt){
	if(step==m){
		ma=max(ma,cnt);
		return ;
	}
	if(u>n)return ;
	if(n-u+1+step<m)return ;
	dfs(u+1,step+1,cnt&a[u]);
	dfs(u+1,step,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,2147483647);
	cout<<ma;
	return 0;
}