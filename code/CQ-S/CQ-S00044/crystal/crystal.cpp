#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[5005][5005],dp1[5005][5005];
long long c[5005],d[5005],d1[5005];
long long a[5005];
long long f=1;
long long g[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		
		c[f++]=a[i];
	}
	if(n<=5000){
		long long cnt=0;
		
		int h=m;
		for(int i=1;i<=n;i++){
			int ans=0;
			h=m;
			for(int j=1;j<=n;j++){
				if(h>=(c[i]-a[j])&&a[j]<=c[i]){
					h-=(c[i]-a[j]);
					++ans;
				}
			}
			
			if(ans>=cnt){
				
					cnt=ans;
				//cout<<c[i]<<' '<<cnt<<' '<<h<<"  ";
				
				
			}
		}
		cout<<cnt;
	}else{
		g[1]=0;
		for(int i=2;i<=n;i++){
			g[i]=g[i-1]+i-1;
		}
		for(int i=1;i<=n;i++){
			if(g[i]>m){
				cout<<i-1;
				break;
			}
		}
		
	}
	
	
	return 0;
} 
