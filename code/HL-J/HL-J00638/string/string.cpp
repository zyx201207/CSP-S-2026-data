#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<long long>a;
	vector<char>c;
	for(int i=0;i<n;i++)
	{
		a.push_back(0);
		c.push_back('0');
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<a.size()-1;i++)
	{
		if(c[i]==c[i+1])
		{
			c.erase(c.begin()+i+1);
			a[i]+=a[i+1];
			a.erase(a.begin()+i+1);
			i--;
		}
		if(a[i]==0)
		{
			c.erase(c.begin()+i);
			a.erase(a.begin()+i);
			i--;
		}
	}
	n=a.size();
	long long ans=0;
	while(n>1)
	{
		if(a[0]>a[n-1])
		{
			a[0]-=a[n-1];
			if(c[0]!=c[n-1])
			{
				ans+=a[n-1];
			}
			a.pop_back();
			c.pop_back();
		}
		else if(a[0]<a[n-1])
		{
			a[n-1]-=a[0];
			if(c[0]!=c[n-1])
			{
				ans+=a[0];
			}
			a.erase(a.begin());
			c.erase(c.begin());
		}
		else
		{
			if(c[0]!=c[n-1])
			{
				ans+=a[0];
			}
			a.pop_back();
			c.pop_back();
			a.erase(a.begin());
			c.erase(c.begin());
			n--;
		}
		n--;
	}
	cout<<ans;
	return 0;
}
