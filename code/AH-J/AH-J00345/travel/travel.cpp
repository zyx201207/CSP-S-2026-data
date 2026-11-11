#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool pd[6]={0,0,0,1,1};
int ch[6]={1,2,3,4,5};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(pd[s1[2]-'A']==pd[s2[2]-'A'])
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(ch[s1[2]-'A']-ch[s2[2]-'A'])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
