#include <bits/stdc++.h>
using namespace std;
//container
string s,ss;
string p,pp;
int c,cc;
//func
bool t(char a,char b){
	if('A'<=a && a<='C'){
		if('D'<=b){
			return 0;
		}else{
			return 1;
		}
	}else{
		if('D'<=b){
			return 1;
		}else{
			return 0;
		}
	}
}
//main
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c>>s>>cc>>ss;
	p = s.substr(0,2);
	pp = ss.substr(0,2);
	if(c == cc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(p == pp && c == cc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(p == pp && t(s[2],ss[2]) && c == cc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs((int)(s[2] - ss[2])) == 1 && p == pp && t(s[2],ss[2]) && c == cc){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
}

