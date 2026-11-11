#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+9;
int n,m;
int a[N];
int pre[N];
int lst[N];
vector<int> G[N];
int zi[N];
int ans[N];
void dfs(int u){
	zi[u]=1;
	for(auto i:G[u]){
		dfs(i);
		zi[u]+=zi[i];
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==0)pre[i]=i+1;
		else pre[i]=lst[a[i]];
		lst[a[i]]=i;
		G[pre[i]].push_back(i);
		//cout<<pre[i]<<' ';
	}
	dfs(n+1);
	for(int i=1;i<=n;i++){
		ans[a[i]]=max(ans[a[i]],zi[i]);
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
} 
/*

*/

