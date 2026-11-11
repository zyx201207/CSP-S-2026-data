#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int c[N];
int vis[N];
int cnt;
void dfs(int x){
	if(x==m+1){
		int ans=c[1];
		for(int i=2;i<=m;i++){
			ans&=c[i];
		}
		cnt=max(cnt,ans);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			c[x]=a[i];
			dfs(x+1);
			c[x]=0;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<cnt;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
} 
