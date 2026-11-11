#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			int a1=s1[2]-'A'+1;
			int a2=s2[2]-'A'+1;
			if(((1<=a1&&a1<=3) && (1<=a2&&a2<=3)) ||( (4<=a1&&a1<=5)&&(4<=a2<=5)))
			{
				cout<<1;
				if(abs(a1-a2)==1)
					cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
 } 
