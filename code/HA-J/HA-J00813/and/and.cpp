#include <bits/stdc++.h>
using namespace std;
long long a[110101];
string s[110010];
string jinzhi(long long n)
{
	string s1="",s2="";
	while(n)
	{
		s2+=(char)(n%2+'0');
		n/=2;
	}
	for(int i=0;i<s2.size();i++)
	{
		s1=s2[i]+s1;
	}
	return s1;
}
long long ZH(string s)
{
	long long k=0,H=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		H+=(s[i]-'0')*pow(2,k);
		k++;
	}
	return H;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		s[i]=jinzhi(a[i]);
	}
	string p=s[n-m+1];
	for(long long i=n-m+2;i<=n;i++)
	{
		string s1=s[i];
		if(s1.size()<p.size())
		{
			for(long long j=0;j<p.size()-s1.size();j++)
			{
				s1="0"+s1;
			}
		}
		if(s1.size()>p.size())
		{
			for(long long j=0;j<s1.size()-p.size();j++)
			{
				p="0"+p;
			}
		}
		string s2="";
		for(int j=0;j<p.size();j++)
		{
			if(p[j]=='1'&&s1[j]=='1')
			{
				s2+="1";
			}
			else
			{
				s2+="0";
			}
		}
		p=s2;
	}
	cout<<ZH(p)<<endl;
	fclose(stdin);
	fclose(stdout);
}
