#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
string c1,c2,s1,s2,s;
bool cp;
bool f(char a,char b){
	if(a<='C'){
		if(a=='A'&&b=='B')return 1;
		if(a=='B'&&b=='A')return 1;
		if(a=='C'&&b=='B')return 1;
		if(a=='B'&&b=='C')return 1;
	}else{
		if(a=='D'&&b=='F')return 1;
		if(a=='F'&&b=='D')return 1;
	}
	return 0;
}
void k(){
	cout<<s;
	ll p=s.size();
	for(int i=1;i<=4-p;i++)cout<<'0';
	return ;
}
void solve(){
	cin>>c1>>s1>>c2>>s2;
    if(c1==c2)s=s+'1';
    else s=s+'0',cp=1;
    if(cp){
		k();
		return ;
	}
    if(s1.substr(0,2)==s2.substr(0,2))s=s+'1';
    else s=s+'0',cp=1;
    if(cp){
		k();
		return ;
	}
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))s=s+'1';
    else s=s+'0',cp=1;
    if(cp){
		k();
		return ;
	}
    if(f(s1[2],s2[2]))s=s+'1';
    else s=s+'0';
    cout<<s;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    solve();
    return 0;
}
//Trick||Treat!
