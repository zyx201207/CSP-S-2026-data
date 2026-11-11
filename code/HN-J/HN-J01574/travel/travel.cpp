#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<'1';
			char a=a2[2],b=b2[2];
			int as=0,bs=0;
			if(a=='A'||a=='B'||a=='C') as=1;
			if(a=='D'||a=='F') as=2;
			if(b=='A'||b=='B'||b=='C') bs=1;
			if(b=='D'||b=='F') bs=2;
			if(as==bs)
			{
				cout<<'1';
				if(abs(a2[2]-b2[2])==1||(as==2&&bs==2)) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
}
