#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a != c)
	{
		printf("0000");
		return 0;
	}
	int pai = 0,ce = 1,ling = 0;
	if(b[0] == d[0] && b[1] == d[1])
	{
		pai = 1;
	}
	if(!pai || (int(b[2]) <= int('C') && int(d[2]) >= int('D')))
	{
		ce = 0;
	}
	if(ce && pai)
	{
		if((int(b[2]) + 1 == int(d[2])) || (int(d[2]) + 1 == int(b[2])))
		{
			ling = 1;
		}
	}
	printf("1");
	printf("%d%d%d",pai,ce,ling);
	return 0;
}
