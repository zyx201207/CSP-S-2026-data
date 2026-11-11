#include<bits/stdc++.h>
using namespace std;
long long n,m,a,p[300100],f[500100],dp[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		if(p[a]!=0) f[p[a]]=i;
		p[a]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]++;
		if(f[i]==0) f[i]=i+1;
		dp[f[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",dp[p[i]]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
