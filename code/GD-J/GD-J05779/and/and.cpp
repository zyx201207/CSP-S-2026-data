#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum,n,m,ans=0;
void dfs(int x,int p){
	if(p==m){
		ans=max(ans,sum);
	}
	if(p==1)sum=a[x];
	int c=sum;
	for(int i=x+1;i<=n;i++){
		sum&=a[i];
		dfs(i,p+1);
		sum=c;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,1);
	}
	cout<<ans;
}
