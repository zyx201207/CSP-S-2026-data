#include <bits/stdc++.h>
using namespace std;
string b[10000];
int ad(string a,string b)
{
	string c;
	int sum=0,ci=1;
	for(int i = max(a.length()-1,b.length()-1);i>=0;i--)
	{
		//if(a[i]!='1') a[i]='0';
		//if(b[i]!='1') b[i]='0';
		if((a[i]=='1')&&(b[i]=='1'))
		{
			c+='1';
			
		}
		else
		{
			c+='0';
		}
	}
	ci=c.length()*2;
	for(int i = c.length()-1;i>=0;i--)
	{
		sum+=(c[i]-'0')*ci;
		ci/=2;
		
	}
	return sum;
}
string er(int n)
{
	string s;
	int x,yu;
	while(n>0)
	{
		
		x = n/2;
		yu= n-x*2;
		char o = yu+48;
		s+=o;
		n/=2;
	}
	string y;
	for(int i = s.length()-1;i>=0;i--)
	{
		y+=s[i];
	}
	return y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000],sum=0;
	cin >>n >> m;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		b[i]=er(a[i]);
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			sum=max(sum,ad(b[j],b[i]));
		}
	}
	cout << sum;
	return 0;
}

