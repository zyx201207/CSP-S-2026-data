#include<iostream> 
using namespace std;
int main()
{
	freopen("travel.in",'r',fopen);
	freopen("travel.out",'w',fopen);
	
	int c1,c2;
	char z1[5],z2[5];
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2)
	{
		cout<<1;
		if(z1[0]==z2[0] && z1[1]==z2[1])
		{
			cout<<1;
			if(z1[2]>='A' && z1[2]<='C' && z2[2]>='A' && z2[2]<='C')
			{
				cout<<1;
				if(z1[2]-z2[2]==1 || z2[2]-z1[2]==1) cout<<1;
				else cout<<0;
			}
			else if((z1[2]=='D' && z2[2]=='F') || (z1[2]=='F' && z2[2]=='D'))
			{
				cout<<11;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
}
