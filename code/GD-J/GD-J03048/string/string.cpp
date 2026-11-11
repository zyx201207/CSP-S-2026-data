#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	int m,c,e;
	char d,f;
	int a[n];
	int cnt=0;
	if(n<=1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cin>>c>>d;
		cin>>e>>f;
		if(d == f)
		{
			cout<<0;
			return 0;
		}
		cout<<abs(c-e);
		return 0;
	}
	cout<< cnt;
	return 0;
 } 
