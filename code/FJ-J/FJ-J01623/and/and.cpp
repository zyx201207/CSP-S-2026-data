#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f;
int a[200005];
int ans=-inf;
int n,m;
void dfs(int c,int sum,int l,int cnt){
	if(c>n){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return;
	}
	for(int i=l+1;i<=n;i++){
		dfs(c+1,sum,l,cnt);
		if(sum==-1){
			dfs(c+1,a[c],c,cnt+1);
		}else{
			dfs(c+1,sum&a[c],c,cnt+1);
		}
	}
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,0,0);
	cout<<ans;
	return 0;
}
