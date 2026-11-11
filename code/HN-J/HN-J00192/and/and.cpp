#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn=INT_MIN;
int n,m;
int a[200005];
void dfs(int x,int sum,int d){
	if(sum>m)return;
	if(x==n+1){
		if(sum==m){
			maxn=max(maxn,d);
		}
		return;
	}
	dfs(x+1,sum+1,d&a[x]);
	dfs(x+1,sum,d);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		dfs(1,0,a[i]);
	}
	cout<<maxn;
	return 0;
}
 
