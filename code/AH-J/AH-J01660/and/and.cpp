#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
int n,m,vmax;
void dfs(int cnt,int sum,int u){
	if(cnt>=m){
		vmax=max(vmax,sum);
		return;
	}
	if(u>n) return;
	dfs(cnt,sum,u+1);
	if(sum==-1) dfs(cnt+1,a[u],u+1); 
	else dfs(cnt+1,sum&a[u],u+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,-1,1);
	cout<<vmax;
	return 0;
}

