#include<bits/stdc++.h>
using namespace std;
string c_1,c_2,s_1,s_2;
void solve()
{
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2) cout<<'1';
	else
	{
		cout<<"0000";
		return;
	}
	if(s_1[0]+s_1[1] == s_2[0]+s_2[1]) cout<<'1';
	else
	{
		cout<<"000";
		return;
	}
	if((s_1[2]<='C' && s_2[2]<='C') || (s_1[2]>='D' && s_2[2]>='D')) cout<<'1';
	else
	{
		cout<<"00";
		return;
	}
	if(int(abs(s_1[2]-s_2[2])) == 1) cout<<'1';
	else
	{
		cout<<'0';
		return;
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
