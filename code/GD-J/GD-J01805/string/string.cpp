#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen(string.in,"r",studin);
	freopen(string.out,"w",studout);
	
	long long x,num=0,n;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		if(a!="a")
		{
			num+=x;
		}
	}
	cout<<num;
	return 0;
}
