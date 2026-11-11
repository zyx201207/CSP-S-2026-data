#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=-9999;
const int N=2e5+3;
bool vis[N];
int a[N];
bool cmp(int x,int y){return x>y;}
void dfs(int step,int sum){
	if(step==m){
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,sum&a[i]);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	if(n>2000){
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++)ans=ans&a[i];
		cout<<ans;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<maxn;
	return 0;
}
