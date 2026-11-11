#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
int c,t,n,d,x[MAXN],dp[5005][5005];
long long ct;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ct=0;
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) dp[i][i]=0;
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				if(j>i){
					for(int k=i+1;k<=j-1;k++){
						if(x[k]-x[i]<=d&&x[j]-x[k]<=d&&x[j]-x[i]>d){
							dp[i][j]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				if(dp[i][j]==2) ct++;
			}
		}
		cout<<ct<<'\n';
	}
	return 0;
}
