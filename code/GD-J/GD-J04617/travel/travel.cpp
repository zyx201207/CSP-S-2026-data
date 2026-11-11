#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2,ans="";
ll ls;
bool flag=false;
bool pd(char x,char y)
{
	if(x=='A'||x=='B'||x=='C')
	{
		if(y=='A'||y=='B'||y=='C')
		{
			ls=(ll)x-(ll)y;
			ls=abs(ls);
			return true;
		}
	}
	else
	{
		if(y=='D'||y=='F')
		{
			ls=(ll)x-(ll)y;
			ls=abs(ls);
			flag=true;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else ans=ans+"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans=ans+"1";
	}
	else ans=ans+"0";
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&pd(s1[2],s2[2])==true)
	{
		ans=ans+"1";
	}
	else ans=ans+"0";
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&pd(s1[2],s2[2])==true&&((flag==true&&ls==2)||(flag==false&&ls==1))) ans=ans+"1";
	else ans=ans+"0";
	cout<<ans;
	return 0;
}
