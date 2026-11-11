#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],dp[300005],id[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//sum[i]=id[a[i]];
		id[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		int j=i;
		while(true){
			if(j>n){
				break;
			}
			int t=a[j];
			j=id[t]+1;
			dp[t]++;
		}
		
	}
	dp[a[n]]++;
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
