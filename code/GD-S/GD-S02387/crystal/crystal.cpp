#include<bits/stdc++.h> 
using namespace std;
const int maxn=5e5+10;
long long a[maxn],d[maxn],sum1[maxn],sum2[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	  d[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)
	  sum1[i]=sum1[i-1]+d[i];
	int st=1;long long sum=0;
	for(int i=1;i<n;i++)
	{
	  	sum+=d[i]*(i-st+1);
	  while(sum>m) 
	  {
	  	st++;
	  	sum=sum-(sum1[i]-sum1[st-1]);
	  }
	  ans=max(ans,i-st+1);
	}
	cout<<ans+1<<endl;
	return 0;
}
