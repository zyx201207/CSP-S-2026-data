#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c[100];
	for (int i=0;i<=3;i++)
	{
		cin>>c[i];
		if (c[1]==c[6] || c[3]+c[4]==c[7]+c[8] || c[4]==c[9])
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
