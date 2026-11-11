#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200005]{0},dp[200005][200005]{0},b[200005];
	int n,k,o=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>b[i];

	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--){
        a[++o]=b[i];

	}
	for(int i=1;i<=n;i++){
        dp[1][i]=a[i];
	}

	for(int i=1;i<=k;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[j]);
        }
	}
	cout<<dp[k][n];
	return 0;
}
