#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn=INT_MIN;
int a[200010];
int node(int x,int y,bool f){
	if(f) return y;
	else return (x&y);
}
void dfs(int x,int g,int sum,bool flag){
	if(x>n){
		if(g==m) maxn=max(maxn,sum);
		return;
	}
	dfs(x+1,g+1,node(sum,a[x],flag),0);
	dfs(x+1,g,sum,flag);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,1);
	cout<<maxn;
	return 0;
}
