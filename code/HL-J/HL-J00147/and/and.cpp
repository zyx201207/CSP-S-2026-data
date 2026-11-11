#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
const int M=-1*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
int n,m,c[N],w[N];
int dp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		w[i]=1;
	}
	dp[0]=M;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],abs(dp[j-w[i]]&c[i]));
		}
	}
	cout<<dp[m];
    return 0;
}
