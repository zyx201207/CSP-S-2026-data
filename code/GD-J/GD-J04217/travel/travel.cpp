#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string x1,x2;
	cin>>c1>>c2>>x1>>x2;
	if(c1==x1)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c2[0]==x2[0]&&c2[1]==x2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	int o=0;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
	{
		o++;
	}
	if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')
	{
		o++;
	}
	if(o==0||o==2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	} 
	if(o==0)
	{
		cout<<1;
		return 0;
	}
	else
	{
		if((c2[2]=='A'&&x2[2]=='C')||(x2[2]=='A'&&c2[2]=='C'))
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
