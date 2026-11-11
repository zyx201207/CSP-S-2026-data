//GZ-J00239 ñûÐÅÖ² 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int i=m;i>1;i--) dp[i]=max(dp[i],dp[i-1]&a[i]);
		dp[1]=max(dp[1],a[i]);
	}
	cout<<dp[m];
	return 0;
}
