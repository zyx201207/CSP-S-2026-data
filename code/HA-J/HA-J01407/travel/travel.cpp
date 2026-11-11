#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,bb,c,dd;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>a>>bb>>c>>dd;
	int x,y;
	x=(bb[0]-'0')*10+bb[1]-'0';
	y=(dd[0]-'0')*10+dd[1]-'0';
	if(a==c)
	{
		cout<<"1";
		if(x==y)
		{
			cout<<"1";
			if(
			(bb[2]>='A'&&bb[2]<='C'&&dd[2]>='A'&&dd[2]<='C')||
			(bb[2]>='D'&&bb[2]<='F'&&dd[2]>='D'&&dd[2]<='F'))
			{
				cout<<"1";
				if(
				(bb[2]>='A'&&bb[2]<='B'&&dd[2]>='A'&&dd[2]<='B')||
				(bb[2]>='B'&&bb[2]<='C'&&dd[2]>='B'&&dd[2]<='C')||
				(bb[2]>='D'&&bb[2]<='F'&&dd[2]>='D'&&dd[2]<='F')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	cout<<endl;
	
	return 0;
}
