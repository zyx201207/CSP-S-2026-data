#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
vector<int> c[35];
void dfs(int dep,vector<int> sum){
	if(dep==-1) return ;
	if(sum.size()>=m){
		ans+=(1<<dep);
		for(int i=0;i<=30;i++) c[i].clear();
		for(int i:sum){
			for(int j=30;j>=0;j--){
			if(i&(1<<j)) c[j].push_back(i);
			}
		}
		dfs(dep-1,c[dep-1]);
	}
	else dfs(dep-1,c[dep-1]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j)) c[j].push_back(a[i]);
		}
	}
	dfs(30,c[30]);
	cout<<ans;
	return 0;
}

