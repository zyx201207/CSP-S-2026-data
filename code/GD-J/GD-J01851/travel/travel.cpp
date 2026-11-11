#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
bool chk1(string s){
	return 'A'<=s[2]&&s[2]<='C';
}
bool chk2(string s){
	return 'D'<=s[2]&&s[2]<='E';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	b1=(c1==c2);
	b2=(s1.substr(0,2)==s2.substr(0,2));
	b3=((chk1(s1)&&chk1(s2))||(chk2(s1)&&chk2(s2)));
	b4=(abs(s1[2]-s2[2])==1);
	if(b1) cout<<1;
	else cout<<0;
	if(b1&&b2) cout<<1;
	else cout<<0;
	if(b1&&b2&&b3) cout<<1;
	else cout<<0;
	if(b1&&b2&&b3&&b4) cout<<1;
	else cout<<0;
	return 0;
}
