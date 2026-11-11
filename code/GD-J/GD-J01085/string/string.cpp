#include<bits/stdc++.h>
using namespace std;
string s;
long long n,sum=0;
long long o=0,p;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long a;
		string c;
		cin>>a>>c;
		p+=a;
		for(long long i=0;i<a;i++)
		{
			s+=c;
		}
	}
	p--;
	if(s.size()%2==1)
	{
		while(o!=p)
		{
			if(s[o]!=s[p])
			{
				sum++;
			}
			o++;
			p--;
		}
	}
	else if(s.size()%2==0)
	{
		bool b=true;
		while((p-o)!=1)
		{
			if(s[o]!=s[p])
			{
				sum++;
				b=false;
			}
			o++;
			p--;
		}
		if(b!=true)
		{
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
