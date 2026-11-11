#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b=0;
	string a="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		string m;
		cin>>m;
			for(int j=1;j<=x;j++)
	{
		a+=m;
	}		
	}
	for(int i=1;i<=a.length()/2;i++)
	{
		if(a[i-1]!=a[a.length()-i])
		{
			b++;
		}
	}
	cout<<b;

	
	
	
	return 0;
}

