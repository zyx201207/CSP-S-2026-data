#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m,a[N],dp[N];
bool b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1]=max(dp[1],a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==dp[1]){
			b[i]=true;
			break;
		}
	}
	for(int i=2;i<=m;i++){
		int x;
		for(x=1;x<=n;x++) if(!b[x]) dp[i]=dp[i-1]&a[x];
		for(int j=x+1;j<=n;j++){
			if(!b[j]&&dp[i]<dp[i-1]&a[j]){
				b[j]=true;
				dp[i]=dp[i-1]&a[j];
			}
		}
	}
	cout<<dp[m];
	return 0;
} 
