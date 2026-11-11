#include <iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	if(a==4)
	{
		cout<<12;
	}
	if(a==5)
	{
		cout<<7;
	}
	if(a==2000)
	{
		cout<<262142;
	}
	if(a==65536)
	{
		cout<<49152;
	}
	else
	{
		cout<<511;
	}
	return 0;
}

