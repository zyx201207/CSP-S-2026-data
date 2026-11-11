#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=INT_MAX;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!f[j]){
				int x=dp[i-1];
				x&=a[j];
				if(x>dp[i])
					dp[i]=x,f[j]=1;
			}
		}
	}
	cout<<dp[m];
	return 0;
}
