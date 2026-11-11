#include <bits/stdc++.h> 
using namespace std;
string c[110];
char s[110];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
	cin>>c[i];
	cin>>s[i];
	if(c[i]==c[i-1])
	{
		cout<<"1";
		if(s[i]==s[i-1])
		{
			cout<<"111" ;
		}	 
	}
	else
	{
		cout<<"0000";
	}
	}
	return 0;
}
