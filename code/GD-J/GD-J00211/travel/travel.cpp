#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int ss,cc;
bool zu(char s,char c){
	if((s>='D'&&s<='F'&&c>='D'&&c<='F')||(s>='A'&&s<='C'&&c>='A'&&c<='C')) return true;
	else return false;
}
bool check(int a,char s,int b,char c){
	if(a+1 == b&&s == c) return true;
	else if(a-1 == b&&s == c) return true;
	else if(a == b&&zu(s,c)&&s+1 == c) return true;
	else if(a == b&&zu(s,c)&&s-1 == c) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(s1 == s2) cout<<1;
	else cout<<0;
	ss = (c1[0]-'0')*10+(c1[1]-'0');
	cc = (c2[0]-'0')*10+(c2[1]-'0');
	if(ss == cc&&(s1 == s2)) cout<<1;
	else cout<<0;
	char s,c;
	s = c1[2]; c = c2[2];
	if(zu(s,c)&&(ss == cc)&&(s1 == s2)) cout<<1;
	else cout<<0;
	if(check(ss,s,cc,c)){
		cout<<1;
	}else cout<<0;
	return 0;
} 
