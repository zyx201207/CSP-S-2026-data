#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,num1="",num2="",lt1="",lt2="";
bool tc(string a,string b)
{
	if(a=="F"||a=="D")
	{
		if(b=="F"||b=="D")
		{
			return true;
		}
		else return false;
	}
	else
	{
		if(b!="F"&&b!="D")
		{
			return true;
		}
		else return false;
	}
}
bool nr(string a1,string a2,string b1,string b2)
{
	if((a2=="F"||a2=="D")&&(b2=="F"||b2=="D"))
	{
		return true;
	}
	else if(a2=="B"&&b2!="F"&&b2!="D")
	{
		return true;
	}
	else if((a2=="C"||a2=="A")&&b2=="B")
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]<='9'&&s1[i]>='0')
		{
			num1+=s1[i];
		}
		else
		{
			lt1+=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]<='9'&&s2[i]>='0')
		{
			num2+=s2[i];
		}
		else
		{
			lt2+=s2[i];
		}
	}
	if(num1!=num2)
	{
		cout<<"1000";
		return 0;
	}
	if(!tc(lt1,lt2))
	{
		cout<<"1100";
		return 0;
	}
	if(!nr(num1,lt1,num2,lt2))
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
