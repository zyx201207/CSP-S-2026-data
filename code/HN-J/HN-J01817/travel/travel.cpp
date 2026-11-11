#include<bits/stdc++.h> 
using namespace std;
char a[3],b[3];
int c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
			c+=1000;
			if(s1[0]!=s2[0]||s1[1]!=s2[1])
			{
			 	cout<<c;
				return 0;
			}
			c+=100;
					if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
				{
					c+=10;
					if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
					{
						c+=1;
						cout<<c;
						return 0;
					} 
					else 
					{
						cout<<c;
						return 0;
					}
				}
				else 
				{
					cout<<c;
					return 0;
				}
	} 
	else cout<<"0000";
	
	return 0;
}
