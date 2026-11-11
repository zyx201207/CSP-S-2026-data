#include<bits/stdc++.h>
using namespace std;
char a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1; i<=4; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=4; i++)
	{
		if(a[i]==a[i+2]||a[i+1]-a[i+3]<=3||a[i+1]-a[i+3]<=3&&a[i+1]+2==a[i+3]||a[i+1]+1==a[i+3])
		{
			cout<<"1";
			
		}
		else
		{
			cout<<"0";
		}
	}
	return 0;
}
