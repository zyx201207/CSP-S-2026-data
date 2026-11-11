#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],dp[500005],dpi[500005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	s[1]=0;
	for(int i=1;i<=n-1;i++){ 
		dpi[i]+=1;
		if(a[i]==a[i+1]){
			dpi[i]++;
			dpi[i+1]++;
		}
	}
	dpi[n]+=1;
	for(int i=1;i<=n;i++){
		dp[0]=dpi[i];
		for(int j=m;j>=1;j--){
			if(j-s[i]*(i-1)>=0){
				dp[j]=max(dp[j-s[i]*(i-1)]+1,dp[j]);
			}else{
				dp[j]=dp[j];
			}
		}	
	}
	cout<<dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
