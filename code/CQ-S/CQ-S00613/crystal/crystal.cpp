#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long sum=0;
	int j=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+a[i];
		while(j<i&&1ll*a[i]*(i-j)-sum>m)
		{
			j++;
			sum=sum-a[j];
		}
		ans=max(ans,i-j);
	}	
	printf("%d\n",ans);
} 
