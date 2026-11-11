#include<bits/stdc++.h>
using namespace std;
//const int mx=;
string a,b,c,d;
map<char,char>mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	mp['A']=mp['B']=mp['C']='l';
	mp['D']=mp['F']='r';
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1])
		{
			cout<<1;
			if(mp[b[2]]==mp[d[2]])
			{
				cout<<1;
				if(b[2]+1==d[2] || b[2]-1==d[2])
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
	cout<<endl;
	return 0;
}
/*



*/

