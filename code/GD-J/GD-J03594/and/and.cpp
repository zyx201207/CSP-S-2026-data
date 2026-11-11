#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans;
bool vis[N];
void dfs(long long t,long long sum){
	if(t==m){
		ans=max(sum,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		if(t==0)dfs(t+1,a[i]);
		else dfs(t+1,sum&a[i]);
		vis[i]=false; 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
} 
