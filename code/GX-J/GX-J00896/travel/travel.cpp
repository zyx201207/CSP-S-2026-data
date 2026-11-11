#include<bits/stdc++.h>
#define rint long long
using namespace std;
string ans;
bool check1(char a,char b){
    if((a>='A' && a<='C') && (b>='A' && b<='C'))return true;
    if(a=='D' and b=='F')return true;
    if(b=='D' and a=='F')return true;
    return false;
}
bool check2(char a,char b){
    if(a=='A' and b=='B')return true;
    if(a=='B' and b=='A')return true;
    if(a=='C' and b=='B')return true;
    if(a=='B' and b=='C')return true;
    if(a=='D' and b=='F')return true;
    if(a=='F' and b=='D')return true;
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string r,x;
	string sr,sx;
	cin>>r>>sr>>x>>sx;
	rint rid=int(sr[0]-'0')*10+int(sr[1]-'0');
	rint xid=int(sx[0]-'0')*10+int(sx[1]-'0');
	if(r==x)ans+='1';
	else ans+='0';
	if(r==x and rid==xid)ans+='1';
	else ans+='0';
	if(r==x and rid==xid && check1(sr[2],sx[2]))ans+='1';
	else ans+='0';
	if(rid==xid and r==x and check1(sr[2],sx[2]) and check2(sr[2],sx[2]))ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
