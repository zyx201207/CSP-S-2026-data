#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	bool flag1=false,flag2=false,flag3=false,flag4=false;
	if(cr[0]==cx[0]&&cr[1]==cx[1]) flag1=true;
	if(flag1&&sr[0]==sx[0]&&sr[1]==sx[1]) flag2=true;
	if(flag2)
	{
		if((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'))
			flag3=true;
		if((sr[2]=='D'||sr[2]=='F')&&(sx[2]=='D'||sx[2]=='F'))
			flag3=true;
	}
	if(flag3&&(abs((int)sr[2]-(int)sx[2])==1)) flag4=true;
	cout<<(flag1? 1:0)<<(flag2? 1:0)<<(flag3? 1:0)<<(flag4? 1:0);
	return 0;
}
