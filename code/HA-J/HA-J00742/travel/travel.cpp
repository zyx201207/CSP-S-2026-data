#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	long long l=0;
	long long l1=s1.size();
	long long l2=s2.size();
	l=max(l1,l2);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		for(int i=0;i<l;i++)
		{
			if(s1[0]+s1[1]==s2[0]+s2[1])
			{
				cout<<"1";
				for(int i=0;i<l;i++)
				{
					if(s1[2]-'A'<=2 && s2[2]-'A'<=2)
					{
						cout<<"1";
						if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
						{
							cout<<"1";
						}
						else
						{
							cout<<"0";
						}
					}
					else if(s1[2]-'D'<=1 && s2[2]-'D'<=1)
					{
						cout<<"1";
						if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
						{
							cout<<"1";
						}
						else
						{
							cout<<"0";
						}
					}
					else
					{
						cout<<"0";
					}
				}
			}
			else
			{
				cout<<"0";
			}
		}
	}
	else
	{
		cout<<"0";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
