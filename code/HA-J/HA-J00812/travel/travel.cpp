#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int s1,s2;
	char s11,s22;
	cin>>c1;
	scanf("%d.2f",&s1);
	cin>>s11;
	
	cin>>c2;
	scanf("%d.2f",&s2);
	cin>>s22;
	

	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		if(s1!=s2)
		{
			cout<<1000;
		}
		else
		{
			if((s11-'A')<=2&&(s22-'A')<=2)
			{
				if((s11-'A')-(s22-'A')==1||(s22-'A')-(s11-'A')==1)
				{
					cout<<1111;
				}
				
				else
				{
					cout<<1110;
				}
			}
			else if((s11-'A')>2&&(s11-'A')<=4&&(s22-'A')<=4&&(s22-'A')>2)
			{
				if((s11-'A')-(s22-'A')==1||(s22-'A')-(s11-'A')==1)
				{
					cout<<1111;
				}
				
				else
				{
					cout<<1110;
				}
			}
			else
			{
				cout<<1100;
			}
		}
	}
	return 0;
}
