#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans[200001],sum,mx,v[200001];
void dfs(int cnt){
	if(cnt==m){
		sum=ans[0];
		for(int i=1;i<m;i++){
			sum=(sum&ans[i]);
		}
		mx=max(mx,sum);
	}
	for(int i=cnt+1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			ans[cnt]=a[i];
			dfs(cnt+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0);
	cout<<mx;
	return 0;
}
