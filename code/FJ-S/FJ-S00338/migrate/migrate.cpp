#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d;
int a[N],dp[1005][1005],ans[1005][1005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		if(n<=1005){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					dp[i][j]=0x7fffffff;
					ans[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)dp[i][j]=1;
					else break;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=j;k<=n;k++){
						if(dp[i][k]==dp[i][j]+dp[j][k]){
							ans[i][k]++;
						}
						if(dp[i][k]>dp[i][j]+dp[j][k]){
							dp[i][k]=dp[i][j]+dp[j][k];
							ans[i][k]=1;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(ans[i][j]==2)cnt++;
				}
			}
			cout<<cnt<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
