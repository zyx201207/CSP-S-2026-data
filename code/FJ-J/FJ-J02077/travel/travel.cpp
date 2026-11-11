#include<iostream>
using namespace std;
int main()
{
	 
	bool a=0,b=0,c=0,d=0;
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		a=1;
		if(c2[0]==c4[0]&&c2[1]==c4[1])
		{
			b=1;
			if((c2[2]<=67&&c4[2]<=67)||(c2[2]>67&&c4[2]>67))
			{
				c=1;
				if(abs(c2[2]-c4[2])==1)
				{
					d=1;
				}
			}	
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
