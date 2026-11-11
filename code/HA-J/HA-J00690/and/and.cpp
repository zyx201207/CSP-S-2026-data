#include<bits/stdc++.h>
#define int long long

using namespace std;
int ans=-1;
int n,m;
int a[200005];
void dfs(int id,int k,int ma){
	if(id>n){
		if(k==m) ans=max(ans,ma);
		return;
	}
	dfs(id+1,k+1,ma&a[id]);
	dfs(id+1,k,ma);
}
bool cmp(int x,int y){
	return x>y;
}
bool flag=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) {flag=0;break;}
	}
	if(flag){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<ans;
	return 0;
}
