#include<bits/stdc++.h>
using namespace std;
string a,aa,s,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>aa>>ss;
	if(a==aa)
	{
		cout<<"1";
		if(s[0]==ss[0]&&s[1]==ss[1])
		{
			cout<<"1";
			if((s[2]=='D'||s[2]=='F')==(ss[2]=='D'||ss[2]=='F'))
			{
				cout<<"1";
				if(abs(s[2]-ss[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
