#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[20005],res=0;
	string str1[20005],str2[20005],b[20005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		res=res+a[i];
		for(int j=1;j<=a[i];j++){
			str1[j]=b[j];
	    }
	}
	for(int o=1;o<=res;o++){
		str2[o]=str1[o];
    }
    long long dp[20005];
    dp[1]=0;
    for(int l=1,u=res;l++,u--;l<=u){
		str2[l]=str1[u];
	}
	for(int m=1;m<=res;m++){
		if(str2[m]==str1[m])dp[m]=dp[m-1];
	    else{
			dp[m]=dp[m-1]+1;
			}
	}
	cout<<dp[res];
	return 0;
}
		
