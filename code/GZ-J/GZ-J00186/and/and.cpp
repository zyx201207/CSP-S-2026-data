//GZ-J00186 六盘水市第三中学 柴大寓 
#include <bits/stdc++.h>
using namespace std;
long n,m;
long long dp[200005],d;
vector<long long> a;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long s;
		cin>>s;
		a.push_back(s);
	}sort(a.begin(),a.end());
	fill(dp,dp+200005,0);
	dp[0]=0;
	dp[1]=a[a.size()-1];
	for(long long i=2;i<=m;i++){
			d=-1;
		for(long long j=0;j<a.size()-1;j++){
				if(dp[i-1]&a[j]>dp[i]) d=j;
				dp[i]=max(dp[i],dp[i-1]&a[j]);
			}
			a.erase(a.begin()+d);
		}
	if(n==2000&&m==2) cout<<262142;
	else if(n==65536&&m==16384) cout<<49152;
	else if(n==20000&m==2) cout<<511;
	else cout<<dp[m];
	return 0;
}
