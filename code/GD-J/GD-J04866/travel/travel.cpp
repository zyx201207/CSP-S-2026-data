#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string num1="",num2="";
	if(c1==c2)
	{
		cout<<1;
	
		for(int i = 0;i<=1;i++)
		{
			num1+=s1[i];
			num2+=s2[i];
		}
		char numb1 = s1[2],numb2 = s2[2];
		if(num1==num2)
		{
			cout<<1;
			if((numb1=='D'||numb1=='E')&&(numb2=='D'||numb2=='E'))
			{
				cout<<11;
				return 0;
			}
			else if((numb1=='A'||numb1=='B'||numb1=='C')&&(numb2=='B'||numb2=='A'||numb2=='C'))
			{
				if(numb1=='B'||numb2=='B')
				{
					cout<<11;
					return 0;
				}else{
					cout<<10;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
 } 
