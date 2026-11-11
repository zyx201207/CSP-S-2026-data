#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1e4;
long long a[maxn],n,m,ans=0;
bool vis[maxn];
void dfs(int deep,long long tmpans){
	if(deep==m+1){
		ans=max(ans,tmpans);
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(deep+1,tmpans&a[i]);
		vis[i]=false;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,1073741823);
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		} 
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--) ans&=a[i];
	cout<<ans;
	return 0;
}
