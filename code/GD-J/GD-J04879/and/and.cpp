#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ans,n,m,t;
void dfs(int step,int node,int cnt){
	if(step==m){
		ans=max(ans,cnt);
		return;
	}
	if(cnt<ans)return;
	if(m-step>n-node+1)return;
	for(int i=node+1;i<=n;i++){
		dfs(step+1,i,cnt&a[i]);
	}
}
int main(){
	t=clock();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,INT_MAX);
	cout<<ans;
	return 0;
}
