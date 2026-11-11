#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int c1,c2,num1,num2;
	c1=(a[0]-48)*10+a[1]-48;
	c2=(c[0]-48)*10+c[1]-48;
	num1=(b[0]-48)*10+b[1]-48;
	num2=(d[0]-48)*10+d[1]-48;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if(num1==num2)
		{
			cout<<"1";
			if(b[2]<='C'&&d[2]<='C')
			{
				cout<<"1";
				if(b[2]-d[2]==1||d[2]-b[2]==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
