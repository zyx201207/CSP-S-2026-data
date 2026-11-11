#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="0000";
bool si(char a,char b){
	if(a<='C'&&b<='C')return 1;
	if(a>='D'&&b>='D')return 1;
	return 0;
}
bool check(char a,char b){
	if(a=='A'&&b=='B')return 1;
	if(a=='B'&&b=='A')return 1;
	if(a=='B'&&b=='C')return 1;
	if(a=='C'&&b=='B')return 1;
	if(a=='D'&&b=='F')return 1;
	if(a=='F'&&b=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if(si(b[2],d[2])){
				ans[2]='1';
				if(check(b[2],d[2])){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
