#include<iostream>
using namespace std;
int c1,c2;
string s1,s2;
bool op[5];
int side[5]={-1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) op[1]=true;
	if(s1[2]<='C') side[1]=1;
	if(s1[2]>'C') side[1]=0;
	if(s2[2]<='C') side[2]=1;
	if(s2[2]>'C') side[2]=0;
	
	for(int i=0;i<3;i++)
	{
		if(i<=1&&s1[0]==s2[0]&&s1[1]==s2[1]&&op[1])
		{
			op[2]=true;
		}
		else if(i==2&&op[2])
		{
			if(side[1]==side[2])
			{
				op[3]=true;
				if((s1[i]-s2[i]==1||s2[i]-s1[i]==1))
				{
					op[4]=true;
				}
			}
	
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<op[i];
	}
	return 0;
}
