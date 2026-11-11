 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r","stdin") ;
	freopen("travel.out","w","stdout") ;
	string a,b; 
	int c1,c2,A,B;
	cin>>c1;
	cin>>A>>a;
	cin>>c2;
	cin>>B>>b;
	if (c1==c2)
	{
		if(B==A)
		{
			if(a=="A",b=="B"||a=="A",b=="C"||a=="B",b=="A"||a=="B",b=="C"||a=="C",b=="A"||a=="C",b=="B"||a=="D",b=="F"||a=="F",b=="D")
			{
				if(a=="A",b=="B"||a=="B",b=="A"||a=="B",b=="C"||a=="C",b=="B"||a=="D",b=="F"||a=="F",b=="D")
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
		 } 
		 else
		 {
		 	cout<<"1000";
		 }
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
