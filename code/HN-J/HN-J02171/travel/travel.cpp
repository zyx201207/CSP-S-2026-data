#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>t;
	int a=s[2]-'A';
	int b=t[2]-'A';
	if(n==m)
	{
		cout<<1;
		if(s[0]==t[0] && s[1]==t[1])
		{
			cout<<1;
			if(max(a,b)<=2 || min(a,b)>=3)
			{
				cout<<1;
				if(abs(a-b)==1)
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
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}



