#include<bits/stdc++.h>
using namespace std;
bool b=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		b=1;
		cout<<0;
	}
	if(!b&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		b=1;
		cout<<0;
	}
	if(!b&&(('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C'))||(('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F')))
		cout<<1;
	else{
		b=1;
		cout<<0;
	}
	if(b&&(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='F')){
		cout<<0;
	}else if(!b&&abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
