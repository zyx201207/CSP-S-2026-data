#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string c1,s1,c2,s2,temp="",temp1="",temp2="",temp3="";
	cin>>c1>>s1>>c2>>s2;
	temp+=s1[0];
	temp+=s1[1];
	temp1+=s2[0];
	temp1+=s2[1];
	temp2+=s1[2];
	temp3+=s2[2];
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else if(temp!=temp1)
	{
		cout<<"1000";
		return 0;
	}
	else if(((temp3<="C" and temp3>="A") and (temp2>="A" and temp2<="C"))==false or (((temp2=="D") and (temp3=="F")) or ((temp2=="F") and (temp3=="D"))==false)==false)
	{
		cout<<"1100";
		return 0;
	}
	else if((((temp2=="A") and (temp3=="B")) or ((temp2=="B") and (temp3=="A")) or ((temp2=="B") and (temp3=="C")) or ((temp3=="B") and (temp2=="C")) or ((temp2=="D") and (temp3=="F")) or ((temp2=="F") and (temp3=="D")))==false)
	{
		cout<<"1110";
		return 0;
	}
	else
	{
		cout<<"1111";
		return 0;
	}
	return 0;
 } 
