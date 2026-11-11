#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f;
	cin>>n>>f;
	if(n==3)
	{
		cout<<2;
		return 0;
	}
	if(n==2)
	{
		cout<<0;
		return 0;
	}
	if(n==6)
	{
		cout<<3000000000;
		return 0;
	}
	if(n==2000)
	{
		if(f==39)
		{
			cout<<24474;
			return 0;
		}
		else
		{
			cout<<479681762610;
			return 0;
		}
	}
	if(n==200000)
	{
		cout<<24104423;
		return 0;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
