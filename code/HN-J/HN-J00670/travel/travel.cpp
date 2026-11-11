#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if(a=='D'&&b=='F') return true;
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')) return true;
	return false;
}
bool check2(char a,char b){
	if(a=='D'&&b=='F') return true;
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')) return true;
	return false;
}
int a,b;
string as,bs;
int aa,bb;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>b>>bs;
	if(a==b){
		cout<<"1";
		aa =(as[0]-'0')*10;
		bb =(bs[0]-'0')*10;
		aa = aa+as[1]-'0';
		bb = bb+bs[1]-'0';
		if(aa==bb){
			cout<<"1";
			if(check1(as[2],bs[2])){
				cout<<"1";
				if(check2(as[2],bs[2])){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
