#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005],ans,dp[25],flag[25];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	
	if(m==1){
		sort(a,a+n,greater<int>());
		ans=a[0];
	}else if(m==n){
		ans=a[0];
		for(int i=0;i<n;i++){
		    ans=ans&a[i];
	    }
	}else if(m==2){
		long long temp=a[0];
		ans=a[0];
		for(int i=0;i<n;i++){
		    for(int j=i+1;j<n;j++){
		        temp=a[i]&a[j];
		        ans=max(ans,temp);
	        }
	    }
	}else if(n<=20){
		sort(a,a+n,greater<int>());
		dp[1]=a[0];
		flag[0]=0;
		for(int i=2;i<=m;i++){
			dp[i]=0;
			for(int j=0;j<n;j++){
			    if((dp[i-1]&a[j])>dp[i]&&flag[j]){
			    	dp[i]=dp[i-1]&a[j];
					flag[j]=0; 
				}
		    }
		}
		ans=dp[m];
	}
	cout<<ans<<endl;
	
	return 0;
}
