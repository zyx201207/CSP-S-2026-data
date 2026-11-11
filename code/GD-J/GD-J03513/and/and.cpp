#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,now,c[200005];
//bool vis[10005][10005];//前n个数的第i个 
ll a[200005],t,maxx;
ll dp[200005];//第n个数 
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    dp[i]=a[i];
	    c[i]++;
	    maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				t=max(t,a[i]&a[j]);
			}
		}
		cout<<t;
	}
	else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx&=a[i];
		}
		cout<<maxx;
	}
	else{
		for(int i=n;i>=1;i--){
		    for(int j=1;j<=i;j++){
		    	if(dp[i]<dp[j]&a[i]){
			    	dp[i]=dp[j]&a[i];
		    	}
	    	}
	   }
    	cout<<dp[n];
	}
	return 0;
} 
