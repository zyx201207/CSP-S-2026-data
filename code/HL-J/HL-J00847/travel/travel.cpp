#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 2e5+10 ;
bool check(char a,char b){
	if(a=='A'&&b=='B'){
		return 1 ;
	}
	if(a=='B'&&b=='A'){
		return 1 ;
	}
	if(a=='B'&&b=='C'){
		return 1 ;
	}
	if(a=='C'&&b=='B'){
		return 1 ;
	}
	if(a=='D'&&b=='F'){
		return 1 ;
	}
	if(a=='F'&&b=='D'){
		return 1 ;
	}
	return 0 ;
}
int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0) ;
	string c1,s1,c2,s2 ; cin>>c1>>s1>>c2>>s2 ;
	if(c1==c2){
		cout<<"1" ;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1" ;
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				cout<<"1" ;
				char a=s1[2],b=s2[2] ;
				if(check(a,b)){
					cout<<"1" ;
				}
				else{
					cout<<"0" ;
				}
			}
			else{
				cout<<"00" ;
			}
		}
		else{
			cout<<"000" ;
		}
	}
	else{
		cout<<"0000" ;
	}
	return 0 ;
}