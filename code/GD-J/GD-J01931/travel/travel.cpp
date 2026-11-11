#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string t1=s1.substr(0,2),t2=s2.substr(0,2);
	if(c1==c2&&t1==t2)cout<<1;
	else cout<<0;
	if(c1==c2&&t1==t2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))cout<<1;
	else cout<<0;
	if(c1==c2&&t1==t2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))cout<<1;
		else if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))cout<<0;
		else if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
