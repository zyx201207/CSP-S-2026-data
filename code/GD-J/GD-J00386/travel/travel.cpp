#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,d;
	string s,ss;
	cin>>a>>s>>d>>ss;
	if(a==d)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}if(s[0]==ss[0]&&s[1]==ss[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}if((s[2]=='D'||s[2]=='F')^(ss[2]=='D'||ss[2]=='F')^1)cout<<1;
	else{
		cout<<"00";
		return 0;
	}if((ss[2]=='A'&&s[2]=='C')||(ss[2]=='C'&&s[2]=='A'))cout<<0;
	else{
		cout<<"1";
		return 0;
	}
	return 0;
}
