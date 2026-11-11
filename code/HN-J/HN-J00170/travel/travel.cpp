#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,c1,c2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool flag1=0,flag2=0;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') flag1=1;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') flag2=1;
	if(c1==c2) cout<<1; //³µÏá 
	else{
		cout<<"0000";
		return 0; 
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1; //Í¬ÅÅ 
	else{
		cout<<"000";
		return 0;
	}
	if(flag1==flag2) cout<<1; //Í¬²à 
	else{
		cout<<"00";
		return 0;
	} 
	if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')) cout<<1;
	else cout<<0;
	return 0;
}

