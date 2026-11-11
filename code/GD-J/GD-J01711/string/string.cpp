#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s,s1,s2,s3;
int n,a[N];
long long ans1,k,ans,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>s1[i];
		k=a[i]+a[i-1];
		for(long long  j=1;j<=a[i];j++)
		{
			s+=s1[i];
		}
	}
	
	long long c=s.size(); 
	if(c%2==0)
	{
		b=c/2;
	}
	else
	{
		b=c/2+1;
	}
	for(long long i=0;i<b;i++)
	{
		for(long long j=k-1;j>=b;j--)
		{
				if(s[i]!=s[j])
				{
					ans1++;
				}
			
		}
	}
		cout<<ans1;




	
	
	
	return 0;
}
