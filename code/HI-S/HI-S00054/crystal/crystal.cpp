#include<bits/stdc++.h>
using namespace std;
int n,s=1,cnt=1,maxx,ls1[500005];
long long m,a[500005],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);                   
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-s);
		cnt++;
		if(dp[i]>m){
			int ls=s+1;
			memset(ls1,0,sizeof(ls1));
			for(int j=i;j>=ls;j--){
				ls1[j]=ls1[j+1]+(a[j]-a[j-1]);
			}
			for(int j=ls;j<=i;j++){
				dp[i]-=ls1[j];
				s++,cnt--;
				if(dp[i]<=m){
					break;
				}
			}
		}
		maxx=max(maxx,cnt);
	}
	printf("%lld",maxx);
	return 0;
} 
