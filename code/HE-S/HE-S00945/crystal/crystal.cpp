#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,anss=0;
	cin>>n>>m;
	long long a[n]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long dp[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j)  continue;
			if(i==j)  dp[i][j]=0;
			dp[i][j]=abs(a[i]-a[j]);
		}
	}
	long long u=m;
	for(int j=2;j<=n;j++){
		m=u;
		anss=0;
		long long t=INT_MAX;
		int x,y;
		while(1){
			t=INT_MAX;
			bool r=0;
			for(int i=1;i<j;i++){
				if(t>dp[i][j]){
					t=dp[i][j];
					x=i;y=j;
					r=1;
				}
			}if(!r){
				break;
			} 
			dp[x][y]=INT_MAX;
			m-=t;
			if(m>=0)  anss++;
			else break;
		}
		ans=max(ans,anss);
	}cout<<ans+1;
	return 0;
} 
 
