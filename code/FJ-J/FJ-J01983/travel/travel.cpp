#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
map<char,int>m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	m['A']=1,m['B']=1,m['C']=1,m['D']=2,m['E']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a==b)
		{
			cout<<1;
			if(m[s1[2]]==m[s2[2]])
			{
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
