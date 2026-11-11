#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=2e5+7;
int a[N];
bool vis[N];
int n,m,ans=0;
void dfs(int num,int cnt){
	if(cnt==m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(!cnt) dfs(a[i],cnt+1);
			else dfs(num&a[i],cnt+1);
			vis[i]=0;
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}else if(n>2000){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
