#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	string q,w;
	bool qq,ww;
	bool ss = true;
	bool a1 = true;
	bool a2 = true;
	bool a3 = true;
	cin>>a>>q>>b>>w;
	if(q[2]=='F'||q[2]=='D')
	{
		qq = true;
	}
	else
	{
		qq = false;
	}
	if(w[2]=='F'||w[2]=='D')
	{
		ww = true;
	}
	else
	{
		ww = false;
	}
	if(a==b)
	{
		cout<<'1';
	}
	else
	{
		a1 = false;
		ss = false;
		cout<<'0';
	}
	if(q[0]==w[0]&&q[1]==w[1]&&a1==true)
	{
		cout<<'1';
	}
	else
	{
		a2 = false;
		ss = false;
		cout<<'0';
	}
	if(qq==ww&&a1==true&&a2==true)
	{
		cout<<'1';
	}
	else
	{
		a3 = false;
		ss = false;
		cout<<'0';
	}
	if(ss==false)
	{
		cout<<'0';
	}
	else
	{
		if((q[2]-1==w[2]||q[2]+1==w[2])&&a1==true&&a2==true&&a3==true)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	return 0;
}

