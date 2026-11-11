#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool vis1=(c1==c2);
	bool vis2=(vis1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool vis3=(vis2&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))));
	bool vis4=(vis3&&(abs(s1[2]-s2[2])==1));
	cout<<vis1<<vis2<<vis3<<vis4;
	return 0;
}

