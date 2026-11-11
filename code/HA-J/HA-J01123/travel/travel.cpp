#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool c,a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=true;
	}
	else{
		cout<<0;
		a=false;
	}
	bool b=s1.substr(0,2)==s2.substr(0,2)?1:0;
	if(a&&b)cout<<1;
	else cout<<0;
	if(a&&b&&!((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))){
		cout<<1;
		c=1;
	}
	else cout<<0;
	if(c&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
