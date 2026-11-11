#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,an[200001],ans=INT_MIN;
void dfs(int s,int x,int i){
	if(s==m){
		ans=max(ans,x);
		cout<<"ans="<<ans<<"\n";
		return;
	}
	if(i>n) return;
	dfs(s+1,x&an[i],i+1);
	dfs(s,x,i+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	for(int i=1;i<=n-m+1;i++) dfs(1,an[i],i+1);
	cout<<ans;
	return 0;
}
