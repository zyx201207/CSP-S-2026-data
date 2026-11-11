#include<bits/stdc++.h>
using namespace std;
int c1,c2,w1,w2,ce;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		w1=s1[i]+w1*10;
		w2=s2[i]+w2*10;
	}
	if(w1==w2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	ce=abs(s1[2]-s2[2]);
	if(w1==w2&&((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D')))
	{
		cout<<1;
		if(ce==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
