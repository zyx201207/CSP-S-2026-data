#include<bits/stdc++.h>
using namespace std;
char c[200001];
int a,b[200001],d,m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i]>>c[i];
	}
	if(a<=1)
	{
		cout<<"0";
		return 0;
	}
	else if(a==2)
	{
		for(int i=1;i<=2;i++)
		{
			if(c[1]==c[2])
			{
				cout<<"0";
				return 0;
			}
			else
			{
				d=min(b[1],b[2]);	
				cout<<d;
				return 0;
			}
		}
	}
	return 0;
}
