#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int che1,che2,cnt,cnt2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) 
	{
		cout<<"1";cnt++;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";cnt++;
			if(b[2]>='D'&&d[2]<'D'||b[2]<'D'&&d[2]>='D')
			{
				cout<<"0";cnt2++;
			}
			else
			{
				cout<<"1";cnt++;
				che1=b[2]-'0';che2=d[2]-'0';
				if(abs(che1-che2)==1)
				{
					cout<<"1";cnt++;
				}
				else
				{
					cout<<"0";cnt2++;
				}
			}						
		}
		else
		{
			cout<<"0";
			cnt2++;
		}	
	}
	else
	{
		cout<<"0";
		cnt2++;
	}
	if(cnt+cnt2<4)
	{
		for(int i=1;i<=4-cnt-cnt2;i++) cout<<"0";
	}
	return 0;
}
