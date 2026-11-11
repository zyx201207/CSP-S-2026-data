#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+1;
long long tg[N];
long long dp[1001][1001],val[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tg[i];
	}
	if(m==1){
		long long maxi=-1;
		for(int i=1;i<=n;i++){
			maxi=max(maxi,tg[i]);
		}
		cout<<maxi;
		return 0;
	}
	if(m==n){
		long long ans=tg[1];
		for(int i=2;i<=n;i++){
			ans=tg[i]&ans;
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long maxj=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxj=max(maxj,tg[i]&tg[j]);
			}
		}
		cout<<maxj;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
