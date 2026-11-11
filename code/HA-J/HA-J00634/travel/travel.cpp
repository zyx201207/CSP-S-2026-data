#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int p1=s1[2]-'0',p2=s2[2]-'0';
	if((p1<=19 && p2<=19) || (p1>19 && p2>19)) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	int k=abs(p1-p2);
	if(p1<=19 && p2<=19 && k==1) cout<<"1";
	else if(p1>19 && p2>19 && k==2) cout<<"1";
	else cout<<"0";
	return 0;
}
