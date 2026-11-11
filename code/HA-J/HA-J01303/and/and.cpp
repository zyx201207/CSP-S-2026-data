#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100102];
int ans=0;
void dfs(int w,int x,int t){
	if(x==m+1){
		ans=max(ans,w);
		return;
	}
	for(int i=t;i<=n;i++){
		if(x>=2){
			dfs(w&a[i],x+1,i+1);
		}else{
			dfs(a[i],x+1,i+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
