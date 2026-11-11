#include<bits/stdc++.h> 
using namespace std;
int c1,s1,c2,s2;
int n1=c1[2],n2=c2[2];
int main()
{
	freopen("travrl.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=1;i<=2;i++)
	{
		cin>>s1[i];
		for(int j=1;i<=2;j++)
		{
			cin>>s2[j];
		}
	}
	if(s1[i]=s2[j])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if()
	retern 0;
}
