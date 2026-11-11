#include <bits/stdc++.h>
using namespace std;
string s,ss;
char c[5],cc[5];
int main()
{
	freopen("travel.in","r",);
	freopen("travel.out","r",);
	cin>>s;
	for(int i=0;i<=2;i++) cin>>c[i];
	cin>>ss;
	for(int i=0;i<=2;i++) cin>>cc[i];
	if(s==ss)
	{
		cout<<"1"; 
	}
	else cout<<"0";
	if(c[0]==cc[0] && c[1]==cc[1] && s==ss)
	{
		cout<<"1"; 
	}
	else cout<<"0";
	if(c[2]=='A' && cc[2]=='B' || c[2]=='B' && cc[2]=='C' || c[2]=='D' && cc[2]=='F' || cc[2]=='A' && c[2]=='B' || cc[2]=='B' && c[2]=='C' || cc[2]=='D' && c[2]=='F' || cc[2]=='A' && c[2]=='C' || c[2]=='A' && cc[2]=='C' && c[0]==cc[0] && c[1]==cc[1] && c[0]==cc[0] && s==ss)
	{
		cout<<"1";
		if((c[2]=='A' && cc[2]=='B') || (c[2]=='B' && cc[2]=='C') || (c[2]=='D' && cc[2]=='F'))
		{
			cout<<"1";
		}
		else 
		{
			cout<<"0";
		}
	}
	else 
	{
		cout<<"00";
	}	
	
	return 0;
}
