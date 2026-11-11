//GZ-J00177 ∫ÿ¡ºÏœ 0fen 
#include<bits/stdc++.h>
using namespace std;
long long dp[200010],m_1=LLONG_MIN;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
		m_1=max(m_1,a[i]);
	}
	if(m==1){
		cout<<m_1;
		return 0;
	}
	for(int i=1 ; i<=m ; i++){
		for(int j=n ; j>=i ; j--){
			if(i==1){
				dp[i]=max(dp[i],a[j]);
			}else dp[i]=max(dp[i],(dp[i-1]&a[j]));
		}
	}
	cout<<dp[m];
	
	return 0;
}
