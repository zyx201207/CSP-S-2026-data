#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],vis[200010],b[200010];
long long ans;
void dfs(int x){
	if(x==m+1){
		long long sum=b[1];
		for(int i=1;i<=m;i++){
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=a[i];
			dfs(x+1);
			b[x]=0;
			vis[i]=0;
		}	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long op=a[1];
		for(int i=2;i<=n;i++){
			op=op&a[i];
		}
		cout<<op;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0; 
}
