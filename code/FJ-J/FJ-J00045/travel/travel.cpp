#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	cout<<"0000";
	else
	{
		cout<<'1'; 
		int x1,x2;
		x1=(b[0]-'0')*10+(b[1]-'0');
		x2=(d[0]-'0')*10+(d[1]-'0');
		if(x1!=x2)
		{
			cout<<"000";
		}
		else
		{
			cout<<"1";
			char x,y;
			x=b[2],y=d[2];
			if(x>y)swap(x,y);
			if(y<='C'||x>='D')
			{
				cout<<"1";
				if((y-1)==x)
				cout<<"1";
				else
				cout<<"0";
			}
			else
			cout<<"00";
		}
	}
	return 0;
}
