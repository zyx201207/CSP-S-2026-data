#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e8;
int n,m,x[MAXN],a[MAXN],ans;
void dfs(int k){
	if(k>m){
		int sum=-1;
		for(int i=1;i<=m;i++){
			sum=(sum&x[a[i]]);
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=a[k-1]+1;i<=n;i++){
		a[k]=i;
		dfs(k+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	dfs(1);
	cout<<ans;
}
