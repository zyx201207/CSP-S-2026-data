#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
//#define int long long
//#define cerr if(0)clog
char isr(const string& s){
	if(s[s.size()-1]=='A')return 0;
	if(s[s.size()-1]=='B')return 0;
	if(s[s.size()-1]=='C')return 0;
	if(s[s.size()-1]=='D')return 1;
	if(s[s.size()-1]=='E')return 1;
	return -1;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b.substr(0,2)!=d.substr(0,2)){
		cout<<"1000";
		return 0;
	}
	if(isr(b)!=isr(d)){
		cout<<"1100";
		return 0;
	}
	if(abs(b[b.size()-1]-d[d.size()-1])>1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
		return 0;
}
