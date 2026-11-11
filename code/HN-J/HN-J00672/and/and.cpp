#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	bool vis[n];
	long long dp[n];
	long long maxx;
	for(int i=0;i<n;i++){
		cin>>dp[i];
	}
	int shu=0;
	for(int i=0;i<n;i++){
		shu=0;
		long long y;
		long long z=1;
		for(int j=i;j<n;j++){
			if(i+z<n){
				if(shu!=m){
					if(vis[j]){
						continue;
					}else{
						y=dp[i];
						y=y&dp[j];
						shu++;
						if(j=i+z){
							vis[j]=true;
						}
					}
				}else{
					z++;
					shu=0;
					j=i;
				}
			}
		}
		dp[i]=max(y,dp[i]);
	}
	cout<<dp[n-1];
	return 0;
}
