#include<bits/stdc++.h>
using namespace std;
bool check(string s,string t){
	bool a,b;
	if('A'<=s[2]&&s[2]<='C') a=0;
	else a=1;
	if('A'<=t[2]&&t[2]<='C') b=0;
	else b=1;
	if(a==b) return 1;
	else return 0;
}
bool f(char a,char b){
	if(a>b) swap(a,b);
	return ((a+1)==b?1:0);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x,s,y,t;
	cin>>x>>s>>y>>t;
	cout<<(x==y?1:0);
	cout<<((x==y&&s.substr(0,2)==t.substr(0,2))?1:0);
	cout<<((x==y&&s.substr(0,2)==t.substr(0,2)&&check(s,t))?1:0);
	cout<<((x==y&&s.substr(0,2)==t.substr(0,2)&&check(s,t)&&f(s[2],t[2]))?1:0);
	return 0;
}

