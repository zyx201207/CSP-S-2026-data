#include<iostream>
#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n,sum=0 ;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string o;
		cin>>x>>o;
		for(int j=1;j<=x;j++)
		{
			a+=o;
		}
	}
	if(a.length()%2==0)
	{
		for(int i=1;i<=a.length()/2;i++)
		{
			if(a[i]!=a[n-i])
			{
				sum++;
			}
		}
	}
	else
	{
		for(int i=1;i<=a.length()/2;i++)
		{
			if(a[i]!=a[n-i])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
