#include<bits/stdc++.h>
using namespace std;
string fun1(int n)
{
	string s="";
	while(n)
	{
		char c=n%2+'0';
		n/=2;
		s=c+s;
	}
	return s;
}
long long a[200005];

long long fun2(string s1,string s2)
{
	long long sum=0;
	int len1=s1.size();
	int len2=s2.size();
	int i=len2-len1;
	string s3;
	for(int j=0;j<s1.size();j++)
	{
		s3[j+i]=s1[i];
	}
	
	for(int j=len2;j>=i;j--)
	{
		int x=1;
		if(s3[i]==s2[i])
		{
			sum+=x;
		}
		x*=2;
	}
	return sum;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	sort(a,a+n);
	if(m==1)
	{
		cout<<a[n-1];
	}
	if(m==2)
	{
	
		long long max1=0;
		for(int i=0;i<n;i++)
		{
			string s1=fun1(a[i]);
			for(int j=i+1;j<n;j++)
			{
				string s2=fun1(a[j]);
				max1=max(max1,fun2(s1,s2));
				
			}
			
		}
		cout<<max1;
		
	}
	return 0;
}
