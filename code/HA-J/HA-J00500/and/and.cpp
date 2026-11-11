#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[25];
long long ans;
void dfs(int k,long long now){
	if(k==m+1){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(k==1){
				now=a[i];
				dfs(k+1,now);
				now=0;
			}else{
				dfs(k+1,now&a[i]);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans;
	}else if(n<=2000){
		if(m==1){
			ans=0;
			for(int i=1;i<=n;i++){
				ans=max(ans,(long long)a[i]);
			}
		}
		else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					ans=max(ans,(long long)a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
