#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=-1;
int m,n;
ll num[200005];
char vis[200005];
void dfs(int g,ll sum){
	if(g==m)
	if(sum>ans) ans=sum;
	else return;
	
	if(sum<=ans) return;
	
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(g+1,sum&num[i]);
		vis[i]=0;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dfs(0,0xffffffff);
	cout<<ans;
}
