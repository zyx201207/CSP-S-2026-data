#include <bits/stdc++.h>
using namespace std;

string c1;
string s1;
string c2;
string s2;
string ans="1111";
int a;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2)
	{
		cout<<"0000"<<'\n';
		return 0;
	}

	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		ans[1]='0';
	}
	
	
	if(ans[1]=='1')
	{
		if((s1[2]-'A'+s2[2]-'A'>=3)&&(s1[2]-'A'+s2[2]-'A'!=7))
		{
			ans[2]='0';
		}
	}else
	{
		ans[2]='0';
	}

	if(ans[2]=='0'||ans[1]=='0')
	{
		ans[3]='0';
	} 
	else
	{
		if(abs(s1[2]-s2[2])!=1)
		{
			ans[3]='0'; 
		}
	}
	
	
	
	cout<<ans<<'\n';

	return 0;	
} 
