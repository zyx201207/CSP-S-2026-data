#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]=='0' && c1[1]=='1' && c2[0]=='0' && c2[1]=='1' || c1[0]=='1' && c1[1]=='6' && c2[0]=='1' && c2[1]=='6')
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2) ans+="1";
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) ans+="1";
	else 
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]<='C' && s2[2]>='D' || s2[2]<='C' && s1[2]>='D')
	{
		cout<<"1100";
		return 0;
	}
	else ans+="1";
	if((s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) ans+="1";
	else 
	{
		cout<<"1110";
		return 0;
	}
	cout<<ans;
	return 0;
}
