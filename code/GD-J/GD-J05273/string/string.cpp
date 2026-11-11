#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[20001];
string s1,s2,s3;;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		
		scanf("%lld %c",&a[i],&c[i]);
		for(long long j=1;j<=a[i];j++)
		{
			s1+=c[i];
		}
	}
	long long ans=0;
	for(long long i=0;i<s1.size()/2;i++)
	{
		long long j=s1.size()-i-1;
		if(s1[i]!=s1[j])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
