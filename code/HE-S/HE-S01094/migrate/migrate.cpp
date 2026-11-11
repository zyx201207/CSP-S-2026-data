#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t; 
	for(int r=1;r<=t;r++){
		int n,a[2000005];
		long long d,dp[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>10&&c<13){
			int ans,lll=0;
			for(int i=0;i*(a[2]-a[1])<=d;i++){
				ans=i;
			}
			for(int i=1;i<=ans;i++){
				lll+=(n-i);
			}
			cout<<lll<<endl;
		}else{
			dp[1]=0;
		    for(int i=2;i<=n;i++){
			    int ans=0;
			    dp[i]=dp[i-1];
			    for(int j=i-1;j>=1;j--){
				    if(a[i]-a[j]>d){
					    break;
				    }
				    ans++;
			    }
			    for(int j=ans-1;j>=0;j--){
				    dp[i]+=(ans-j);
			    }
		    }
		    cout<<dp[n]<<endl;
		}
		
	}
	cout<<6;
	return 0;
}
