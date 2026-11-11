#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;

bool lr(char c)
{
	if(c=='A' || c=='B' || c=='C') return true;
	return false;
}



signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2);
	bool b=(s1[0]==s2[0] && s1[1]==s2[1]);
	bool c=(lr(s1[2]) && lr(s2[2]));
	bool d1=(s1[2]==char(s2[2]+1) || s2[2]==char(s1[2]+1));
	bool d2=((s1[2]!='D' && s2[2]!='C') && (s1[2]!='C' && s2[2]!='D'));
	
	if(a) cout<<1;
	else cout<<0;
	
	if(a && b) cout<<1;
		else cout<<0;
		
	if(a && b && c) cout<<1;
		else cout<<0;
		
	if(a && b && d1 && d2) cout<<1;
		else cout<<0;
	
	return 0;
}
