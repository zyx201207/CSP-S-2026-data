#include <bits/stdc++.h>
using namespace std;
bool f(char x){
	if(x=='A'||x=='B'||x=='C') return 1;
	return 0;
}
bool check(char x,char y){
	if(max(x,y)-min(x,y)==1) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;		
	}
	if(b[0]+b[1]==d[0]+d[1]){
		cout<<"1";
		if(f(b[2])==f(d[2])){
			cout<<"1";
			if(check(b[2],d[2])) cout<<"1";
			else cout<<"0";
		}else cout<<"00";
	}else cout<<"000";
	return 0;
}
