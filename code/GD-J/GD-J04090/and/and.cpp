#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxx=-1;
bool vis[100005],vi[100005];
void dfs(int sum,int cnt,int pot){
	if(cnt>m){
		maxx=max(maxx,sum);
		return;
	}
	if(!vi[sum]){
		for(int i=pot+1;i<=n;i++){
			dfs(sum&a[i],cnt++,i);
		}
		vi[sum]=1;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(!vis[a[i]]){
			dfs(a[i],1,1);
			vis[a[i]]=1;
		}
	}
	cout<<maxx;
	return 0;
}
