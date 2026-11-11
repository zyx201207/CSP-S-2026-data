#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	int c1,c2;
 	string s1,s2;
 	cin>>c1>>s1>>c2>>s2;
 	int pai1,pai2,lie1,lie2;
 	pai1=s1[0]*10+s1[1];
 	pai2=s2[0]*10+s2[1];
 	lie1=s1[2]-'A';
 	lie2=s2[2]-'A';
 	if(c1==c2)
 	{
 		cout<<1;
 		if(pai1==pai2)
 		{
 			cout<<1;
 			if(lie1==0||lie1==1||lie1==2)
 			{
 				if(lie2==0||lie2==1||lie2==2)
 				{
 					cout<<1;
 					if(lie1-lie2==1||lie1-lie2==-1)
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				 }
				 else
				 {
				 	cout<<"00";
				 }
			}
			else if(lie1==3||lie1==4)
			{
				if(lie2==3||lie2==4)
				{
					cout<<1;
					if(lie1-lie2==1||lie1-lie2==-1)
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				}
				else
				{
					cout<<"00";
				}
			}
		 }
		 else
		 {
		 	cout<<"000";
		 }
	 }
	 else
	 {
	 	cout<<"0000";
	 }
 	return 0;
}

