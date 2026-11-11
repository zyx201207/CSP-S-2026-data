#include<bits/stdc++.h>
using  namespace  std;
string c1,s1,c2,s2;
int  main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=17;i++)
	{
		if(c1==02||c2==02&&s1==01"A"||s2==02"B")
		{
			cout<<"1111";
		}
		else
		{
			break;
		}
		if(c1==02||c1==02&&s1==01"C"||s2==02"A")
		{
			cout<<"1110";
		}
		else
		{
			break;
		}
		if(c1==02||c2==02&&s1==01"C"||s2==01"D")
		{
			cout<<"1100";
		}
		else
		{
			break;
		}
		return  0;
}
