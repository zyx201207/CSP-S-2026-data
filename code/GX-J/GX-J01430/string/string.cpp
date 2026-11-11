#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m=1;
int p[2000005];
int dp[5005][5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		int d=(int)(c-'a'+1);
		for(int j=1;j<=a[i];j++){
            p[m]=d;
            m++;
		}
	}
	for(int len=2;len<=m-1;len++){
        for(int l=1;l+len-1<=m-1;l++){
            int r=l+len-1;
            dp[l][r]=dp[l+1][r-1]+(p[l]!=p[r]);
        }
	}
	cout<<dp[1][m-1];
	return 0;
}
