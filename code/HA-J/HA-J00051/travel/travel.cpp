#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int car_R,car_X;string sit_R,sit_X; 
	cin >> car_R>>sit_R>>car_X>>sit_X; 
	if(car_R==car_X)
	{
		cout<<'1';
		if(sit_R[0]==sit_X[0]&&sit_R[1]==sit_X[1])
		{
			cout <<'1';
			if((sit_R[2]<'D'&&sit_X[2]<'D')||(sit_R[2]>'C'&&sit_X[2]>'C'))
			{
				cout << '1';
				if(abs(sit_R[2]-sit_X[2])==1||(sit_R[2]=='F'&&sit_X[2]=='D')||(sit_R[2]=='D'&&sit_X[2]=='F'))
				{
					cout << '1';
				}
				else
				{
					cout << '0';
				}	
			}
			else
			{
				cout << "00";
			}	
		}
		else
		{
			cout << "000";
		}
			
	}
	else
	{
		cout << "0000";
	}	
	return 0;
}
