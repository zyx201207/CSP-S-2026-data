#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1,ans;
	cin>>a>>a1>>b>>b1;
	int wz,wz1;
	wz=a1[2]-'A'+1;
	wz1=b1[2]-'A'+1;
	if(a==b)
	{
		string p,p1;
		p=a1[0]+a1[1];
		p1=b1[0]+b1[1];
		if(p==p1)
		{
			
			if((wz<=3&&wz1<=3)||(wz>3&&wz1>3))
			{
				if(max(wz,wz1)-min(wz,wz1)==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}	
			}
			else
			{
				cout<<"1100";
			}
		}
		else
			cout<<"1000";
		
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
