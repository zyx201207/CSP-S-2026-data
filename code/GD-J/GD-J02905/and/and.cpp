#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,l,ans;
int a[200005],dp[200005],vis[200005];
void dfs(int k,int sum){
	//cout<<sum<<" ";
	if(k>m){
		ans=max(ans,sum);
		//cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum==-1) dfs(k+1,a[i]);
			else dfs(k+1,sum&a[i]);
			vis[i]=0;
			//cout<<a[i]<<" "<<k<<" "<<sum<<endl; 
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	l=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		l=(l&a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==n) cout<<l;
	else if(m==2){
		int c=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					c=max(c,(a[i]&a[j]));
				}
			}
		}
		cout<<c;
	}
	else if(n<=2000){
		dfs(1,-1);
		cout<<ans;
	}
	return 0;
}
