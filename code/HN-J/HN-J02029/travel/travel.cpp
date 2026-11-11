#include<bits/stdc++.h>
using namespace std;
double s1[20],c1[20],s2[20],c2[20];
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%d%d",&s1,&c1,&s2,&c2);
	for(int k=1;k<=17;k++)
	{
		if(s1[k]-s2[k]==0)
		{
			cout<<"yes";
		}
		else
		{
			cout<<"no";	
		}
	}
	
	for(int i=1;i<=18;i++)
	{
		for(int j='A';j<='F';j++) 
		{
			if(c1[i]==c2[i]&&c1[j]==c2[j])
			{
				cout<<"yes";
			}
			else
			{
			cout<<"no";	
			}
		}
	}
		
	return 0;
}
