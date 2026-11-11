#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b;
	char a1,b1;
			
	cin>>n>>a>>a1>>b>>b1;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		if(a>b)
		{
			cout<<b;
			return 0;
		}
		if(b>a)
		{
			cout<<a;
			return 0;
		}
		if(b==a)
		{
			cout<<"0";
			return 0;
		}
		
	}
	cout<<"0";
return 0;
}
