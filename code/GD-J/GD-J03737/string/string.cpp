#include <iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	else if(n==2)
	{
		string a,y,b,x;
		cin>>a>>x>>b>>y;
		if(x==y && a==b)
		{
			cout<<"0";
			return 0;
		}
		else
		{
			if(a>b)
			{
				cout<<b;
				return 0;
			}
			else
			{
				cout<<a;
				return 0;
			}
		}
	}
	return 0;
}
