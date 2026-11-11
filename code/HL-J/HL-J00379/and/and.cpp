#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0;
int a[200010];
void dfs(int res,int cnt,int pos){
	if(cnt==m){
		ans=max(ans,res);
	}else{
		for(int i=pos+1;i<=n;i++){
			//
			dfs(a[i]&res,cnt+1,i);
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
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		for(int i=2;i<=n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	} 
	for(int i=1;i<=n-m;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	return 0;
} 
