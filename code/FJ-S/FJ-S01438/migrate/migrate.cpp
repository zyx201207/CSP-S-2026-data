#include<bits/stdc++.h>
using namespace std;
int a[500005];
int vis[1005][1005];int n,d;
int dfs(int n,int q,int l,int cnt){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j]>=2){
				vis[i][j]-=2;
				cnt++;
			}
		}
		} 
	for(int i=1;i<=n;i++){
		  	for(int j=n;j>=i;j--){
		  		if(a[i]+d>=a[j]){
		  			vis[i][j]++;
		  			dfs(n,q+1,l+a[i+1]-a[i],cnt);
		  			if(q==n){
		  				return cnt;
					  }
				  }
			  }
		  }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
      int n,d;
	  cin>>n>>d;
	  	for(int i=1;i<=n;i++){
	  		cin>>a[i];
		  }
		  
		  cout<<dfs(n,1,0,0);
	}
   
	return 0;
} 
