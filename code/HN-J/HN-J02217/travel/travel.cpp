#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int c1,c2,s1,s2,ss1,ss2,sss1,sss2;
	freopen("travel.in","r",stdin);
	cin>>c1>>c2>>s1>>s2;
	if(s1!=1&&s1!=16)
	if(c1==c2)
	cout<<"1";
	else
	cout<<"0";
	else 
	cout<<"0";
	if(s1!=s2)
	{
	ss2=s2/10;
	ss1=s1/10;
	if(ss1==ss2&&c1==c2)
	cout<<"1";
	else
	cout<<"0";
	}
	else
	cout<<"0";
	sss1=s1%10;
	sss2=s2%10;
	if(ss1==ss2&&c1==c2&&sss1==sss2)
	cout<<"1";
	else
	cout<<"0";
	if(sss1==sss2&&ss1==ss2)
	cout<<"0";
	else
	{
	if(sss1==sss2&&ss1+1==ss2)
	cout<<"1";
	else
	if(ss1==ss2&&sss1+1==sss2)
	cout<<"1";
	else
	cout<<"0";
	}
	
	freopen("travel.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
