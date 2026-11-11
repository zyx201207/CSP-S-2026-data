#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N=2e5+5;
long long a[200005] ;ll dp[2005][2005];
int n,m;
int dfs(int i,int j,long long b){

	if(i>n||j==0){
		return b;
	}
	if(dp[i][j]!=0){
	
		return dp[i][j] ;
	}else{
		int x=a[i]&b;
		if(b==0)x=a[i];
		dp[i][j]=max(dfs(i+1,j-1,x),dfs(i+1,j,b));
		return dp[i][j];
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
	}if(n==m){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout << a[n];
		return 0;
	}
	if(m==1){
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout << ans ;
		return 0;
	}
	if(m==2){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout << dfs(1,m,0) ;
	
	return 0;
}


