#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,i,j,k,a[10005],b,c,d;
string s,l,ss,ll;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>l>>ll;
	if(s!=l)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if(ss[0]==ll[0]&&ss[1]==ll[1])
		{
			cout<<"1";
			if(ss[2]=='D'&&ll[2]=='F'||ss[2]=='F'&&ll[2]=='D')
			{
				cout<<"11";
			}
			else if(ss[2]=='A'&&ll[2]=='B')
			{
				cout<<"11";
			}
			else if(ss[2]=='A'&&ll[2]=='C')
			{
				cout<<"10";
			}
			else if(ss[2]=='B'&&ll[2]=='A')
			{
				cout<<"11";
			}
			else if(ss[2]=='B'&&ll[2]=='C')
			{
				cout<<"11";
			}
			else if(ss[2]=='C'&&ll[2]=='A')
			{
				cout<<"10";
			}
			else if(ss[2]=='C'&&ll[2]=='B')
			{
				cout<<"11";
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
	return 0;
}
