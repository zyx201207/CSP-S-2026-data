#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,c1,s2,c2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char ca=c1[2],cb=c2[2];
	bool flag=0;
	if((ca=='F'||ca=='D')&&(cb=='F'||cb=='D'))
	{
		cout<<1;
		flag=1;
	}
	else if((ca=='A'||ca=='B'||ca=='C')&&(cb=='A'||cb=='B'||cb=='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(flag) cout<<1;
	if((ca=='A'&&cb=='B')||(ca=='B'&&cb=='A')||(ca=='C'&&cb=='B')||(ca=='B'&&cb=='C'))
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
