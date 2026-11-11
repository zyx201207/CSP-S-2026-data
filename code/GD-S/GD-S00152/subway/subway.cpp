#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m+1);
	vector<vector<long long>> sw(n,vector<long long>(m+1,0));
	vector<vector<long long>> dp(m+1,vector<long long>(m+1,100000000000000000));
	vector<vector<bool>> f(n,vector<bool>(m+1,false));
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=0;i<n;i++){
		long long k;
		cin>>k;
		for(long long j=0;j<k;j++){
			long long a,t;
			cin>>a>>t;
			sw[i][a]=t;
		}
	}
	for(long long i=1;i<=m;i++) dp[i][i]=0;
	for(long long i=0;i<n;i++){
		for(long long j=1;j<m;j++){
			for(long long k=j+1;k<=m;k++){
				if(sw[i][j] && sw[i][k]){
					long long x=sw[i][j]+sw[i][k];
					if(x<dp[j][k]){
						dp[j][k]=x;
						dp[k][j]=x;
						f[j][k]=true;
						f[k][j]=true;
					}
				}
			}
		}
	}

	for(long long i=0;i<q;i++){
		long long st1,to1;
		cin>>st1>>to1;
		cout<<dp[st1][to1]+w[st1]+w[to1];
	}
	return 0;
}
