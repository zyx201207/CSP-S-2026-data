#include<bits/stdc++.h>
using namespace std;

long long n;

long long a[200005];

char c[200005];

string s;

string st;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	long long sum=0;
	
	for(long long i=0;i<n;++i)
	{
		cin>>a[i]>>c[i];
		
		for(long long j=0;j<a[i];++j)
		{
			s[j]=c[i];
		}
		
		sum+=a[i]; 
		
	}
	
	char c1=c[0];
	
	long long cnt=0;
	
	for(int i=1;i<n;++i)
	{
		if(c1==c[i])
		{
			cnt++;
		}
	}
	if(cnt==n-1&&sum%2==1)
	{
		cout<<0;
		return 0; 
	}
	
	long long l=0;
	
	for(long long i=0;i<n;++i)
	{
		l+=a[i];
	}
	
	long long ans=0;
	
	for(long long i=0;i<l;++i)
	{
		st[i]=s[l+1-i];
		
		if(st[i]!=s[i])
		{
			s[i]=st[i];
			
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
