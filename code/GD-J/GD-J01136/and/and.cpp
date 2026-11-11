#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200000+10],dp[200000+10];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}
