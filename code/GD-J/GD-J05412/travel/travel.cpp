#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rche,Xche,Rzuo,Xzuo;
	cin>>Rche>>Rzuo>>Xche>>Xzuo;
	if(Rche!=Xche)
	{
		cout<<"0000";
	}
	else{
		if((Rzuo[0]!=Xzuo[0]) || (Rzuo[1]!=Xzuo[1]))
		{
			cout<<"1000";
		}
		else{
			if(Rzuo[2]=='D' || Rzuo[2]=='F')
			{
				if(Xzuo[2]!='D' && Xzuo[2]!='F')
				{
					cout<<"1100";
				}
				else
				{
					cout<<"1111";
				}
			}
			else
			{
				if(Xzuo[2]!='A' && Xzuo[2]!='B' && Xzuo[2]!='C')
				{
					cout<<"1100";
				}
				else
				{
					if((Rzuo[2]=='A' && Xzuo[2]=='C') || (Rzuo[2]=='C' && Xzuo[2]=='A'))
					{
						cout<<"1110";
					}
					else{
						cout<<"1111";
					}
					}
				}
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
