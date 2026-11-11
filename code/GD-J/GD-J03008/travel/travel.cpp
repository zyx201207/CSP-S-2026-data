#include <bits/stdc++.h>
using namespace std;
bool check(string s1,string s2)
{
	char first=s1[2],second=s2[2];
	if((first==second-1)&&(first!='C'&&second!='D'))
	    return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	    cout<<1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		{
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				cout<<1;
				if(check(s1,s2))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}	
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
} 
