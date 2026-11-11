#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	char	e[10][3];
	for(int i=1;i<=2;i++)
       for(int j=1;j<=5;j++)
       {       
	   	cin>>e[j][i];
	   }
	if(e[1][1]==e[1][2]&&e[2][1]==e[2][2])
	{
		a=1;
		if(e[3][1]==e[3][2]&&e[4][1]==e[4][2])
		{
			b=1;

           if(e[5][1]=='A'||e[5][1]=='B'||e[5][1]=='C')
           {
           	if(e[5][2]=='A'||e[5][2]=='B'||e[5][2]=='C')
           	{
           		c=1;
           		if(abs(e[5][2]-e[5][1])==1)
           		d=1;
           		else d=0;
			   }
			   else {
			   	c=0;d=0;
			   }
		   }
			else{
				if(e[5][2]=='D'||e[5][2]=='F')
				{
					c=1;
					d=1;
				}
				else{
					c=0;d=0;
				}
			}

			
		}
		else {
			b=0;c=0;d=0;
		}
	}
	else {
		a=0;b=0;c=0;d=0;
	}

   cout<<a<<b<<c<<d;

	fclose(stdin);
fclose(stdout);
	return 0;
}
