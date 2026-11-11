#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long n,d;
long long x[N];
long long dp[N];
long long ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int k=3;k<=n-1;k++)
			for(int i=1;i<=n-k;i++){
				int f=0;  
				for(int j=1;j<=k;j++){
					if(x[i+j]-x[i+j-1]>d)f=1;
				}
				if(f==0&&(x[i+k]-x[i])/d==k-2&&(x[i+k]-x[i])%d!=0)ans++;
			}
			cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
