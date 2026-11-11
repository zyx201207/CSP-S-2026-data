#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,dp[1000000],ans,bj[1000000];
string f[1000000];
int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		ans=max(ans,a[i]);
	}
	cout<<ans;
 	return 0;
}
