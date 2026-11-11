#include<bits/stdc++.h>
using namespace std;
long long a[200010];int n,m;long long ans=0;
bool vis[200010];
void dfs(int now,long long num){
	if(now==m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(now==0){
				vis[1]=1;
				dfs(now+1,a[1]);
			}
			vis[i]=1;
			dfs(now+1,num&a[i]);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx)mx=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15
wtfwtfwtfwtf
*/
