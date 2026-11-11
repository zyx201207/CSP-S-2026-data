#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+5;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int lens=0; 
	string s1,s2,s3,s4,ans;
	cin>>s1>>s2>>s3>>s4;
	
	if(s1==s3) ans+='1';
	else ans+='0';
	
	if(s2[0]==s4[0] && s2[1]==s4[1] && ans[lens]=='1') ans+='1';
	else ans+='0';
	lens++;
	
	int u,v;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') u=0;
	else u=1;
	if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C') v=0;
	else v=1;
	if(u==v && ans[lens]=='1' && ans[lens-1]=='1') ans+='1';
	else ans+='0';
	lens++;
	
	if(ans[lens]=='0') ans+='0';
	else if(u==1 && v==1) ans+='1';
	else
	{
		if(s2[2]=='A' && s4[2]=='B' || s2[2]=='B' && s4[2]=='C') ans+='1';
		else if(s2[2]=='B' && s4[2]=='A' || s2[2]=='C' && s4[2]=='B') ans+='1';
		else ans+='0';
	}
	cout<<ans;
	return 0;
}
/*
02 01A 03 01A
02 02B 02 01A
02 01C 02 01D
02 01C 02 01A
02 01A 02 01B
*/
