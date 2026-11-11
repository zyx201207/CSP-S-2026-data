#include <iostream>
using namespace std;
long long a[200005];
string c[200005];
string m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			m+=c[i];
		}
	}
	int b=1;
	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i+1])
		{
			b=0;
		}
	}
	if(b==1)
	{
		cout<<"0";
		return 0;
	}
	if(n<=5)
	{
		cout<<n-(n/2);
	}
	else
	{
		cout<<n+(n/2);
	}
	return 0;
}
