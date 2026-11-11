#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long c1,c2,i=0,j;
	string x,y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x>>c2>>y;
	if(c1==c2)
	{
		cout<<"1";
		i++;
		if(x[0]==y[0]&&x[1]==y[1])
		{
			cout<<"1";
			i++;
			if((x[2]<='C'&&x[2]>='A'&&y[2]<='C'&&y[2]>='A')||(x[2]<='E'&&x[2]>='D'&&y[2]<='E'&&y[2]>='D'))
			{
				cout<<"1";
				i++;
				if(abs(int(x[2]-y[2]))==1)
				{
					cout<<"1";
					i++;
				}
			}
		}
	}
	for(j=4;j>i;j--)cout<<"0";
	return 0;
}
