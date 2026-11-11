#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool lr(char a,char b){
	if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')){
		return 1;
	}if((a=='D' || a=='F') && (b=='D' || b=='F')){
		return 1;
	}
	return 0;
}
bool beside(char a,char b){
	if((a=='A' && b=='B') || (a=='B' && b=='A')){
		return 1;
	}if((a=='B' && b=='C') || (a=='C' && b=='B')){
		return 1;
	}if((a=='D' && b=='F') || (a=='F' && b=='D')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if(lr(s1[2],s2[2])){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(beside(s1[2],s2[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

