#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int n,m,s,w=0;
long long int a[N],dp[N],sum=1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	/*for(int i=1;i<=n;i++){
		if(a[n/2])
	}*/
	
	for(int i=1;i<=n;i++){
		if(a[i]+m>a[i+1]){
			w=1;
		} 

	}
	s=n/2;
	if(w==0){
		cout<<1; return 0;
			
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=a[i];k<=s+1;k++){
					dp[k]=max(dp[k],dp[k-a[i]]+1);
				}
			} 
		}
	} 
	
	
	cout<<dp[s+1];
	return 0;
} 
