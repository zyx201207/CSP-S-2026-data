#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<"1";
		if(int(sr[0])*10+int(sr[1])==int(sx[0])*10+int(sx[1]))
		{
			cout<<"1";
			if(sr[2]<='C'&&sx[2]<='C'||sr[2]>='D'&&sx[2]>='D')
			{
				cout<<"1";
				if(abs(int(sr[2]-'A')-int(sx[2]-'A'))==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}