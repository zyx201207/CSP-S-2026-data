#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[210000];
int ans=INT_MIN;

int n,m;
void dfs(int x,int t,int sum){
	if(x>n) return;
	if(t==m){
		ans=max(ans,sum);
		return;
	}
		
	dfs(x+1,t,sum);
	if(sum==0){
		dfs(x+1,t+1,a[t]);
	}
	
	else dfs(x+1,t+1,sum&a[t]);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
