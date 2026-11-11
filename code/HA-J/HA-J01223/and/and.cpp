#include <iostream>
#include <string>
using namespace std;
long long  m,n; 
string er(long long r)
{
	string s="";
	while (r>=1)
	{
		s+=('0'+r%2);
		r/=2;
	}
	int a=s.length();
	string d;
	for (int i=a;i>=0;i--)
	{
		d+=s[i];
	}
	return d;
}
int shu (string r)
{
	int s=r.length(),d=0;
	for (int i=0;0<s;i++)
	{
		if (r[i]==1)
		{
			d++;
		}
	}
	return d;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int g[m],f=0;
	while (n>0)
	{
		n--;
		int a;
		cin>>a;
		if (f!=(m-1))
		{
			g[f]=a;
		}
		else
		{
			for (int i=0;i<=f;i++)
			{
				if (shu(er(g[i]))<shu(er(a)))
				{
					g[i]=a;
				}
				else if(shu(er(g[i]))==shu(er(a)) && a>g[i])
				{
					g[i]=a;
				}
			}
		}
	}
	int lei=g[0];
	for (int i=1;i<f;i++)
	{
		lei=lei&g[i];
	}
	cout<<lei;
}
