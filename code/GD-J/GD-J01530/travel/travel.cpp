#include<bits/stdc++.h>
using namespace std;
string s,s1,q,q1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>q>>q1;
	if(s==q)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==q1[0] && s1[1]==q1[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (q1[2]=='D' || q1[2]=='E') || ((q1[2]=='A' || q1[2]=='B' || q1[2]=='C') && (s1[2]=='D' || s1[2]=='E'))){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if((s1[2]=='B' && (q1[2]=='A' || q1[2]=='C')) || (q1[2]=='B' && (s1[2]=='A' || s1[2]=='C')) || (s1[2]=='D' && q1[2]=='E') || (q1[2]=='D' && s1[2]=='E')){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
