#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='A'&&b=='C'||a=='D'&&b=='F'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='C'&&b=='A'||a=='F'&&b=='D'){
		return true;
	}else return false;
}
bool check2(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='F'&&b=='D'){
		return true;
	}else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(check(s1[2],s2[2])){
				cout<<1;
				if(check2(s1[2],s2[2])){
					cout<<1;
				}cout<<1110;
			}else cout<<1100;
		}else cout<<1000;
	}else cout<<0000;
	cout<<'\n';
	return 0;
}
