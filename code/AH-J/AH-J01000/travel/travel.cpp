#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
void solve(){
	a=s1[2];
	b=s2[2];
	s1.erase(2,1);
	s2.erase(2,1);
}
bool check1(){
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')) return true;
	if((a=='D'||a=='E')&&(b=='D'||b=='E')) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	solve();
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(check1()) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((a=='A'&&b=='C')||(a=='C'||b=='A')) cout<<0;
	else cout<<1;
	return 0;
}
