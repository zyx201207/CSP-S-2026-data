#include<bits/stdc++.h> 
using namespace std;
string c1,c2,c3,c4;
//int ans=1;
bool f(string a,string b,int st,int en)
{
	for(int i=st;i<=en;i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(f(c1,c3,0,1))
	{
		cout<<1;
		if(f(c2,c4,0,1))
		{
			cout<<1;
			if((c2[2]=='F'&&c4[2]=='D')||(c2[2]=='D'&&c4[2]=='F')
			||(c2[2]=='C'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='C')
			||(c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='A'))
			{
				cout<<"11";
			}
			else if((c2[2]=='A'&&c4[2]=='C')||(c2[2]=='C'&&c4[2]=='A'))
				cout<<"10";
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
	else cout<<"0000";
	return 0;
}
