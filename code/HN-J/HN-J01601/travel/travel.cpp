#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1(char a, char b){
	if(a=='A' && b=='D') return 1;
	if(a=='A' && b=='E') return 1;
	if(a=='B' && b=='D') return 1;
	if(a=='B' && b=='E') return 1;
	if(a=='C' && b=='D') return 1;
	if(a=='C' && b=='E') return 1;
	if(b=='A' && a=='D') return 1;
	if(b=='A' && a=='E') return 1;
	if(b=='B' && a=='D') return 1;
	if(b=='B' && a=='E') return 1;
	if(b=='C' && a=='D') return 1;
	if(b=='C' && a=='E') return 1;
	return 0;
}
int f2(char a,char b){
	if(a=='A' && b=='B') return 0;
	if(a=='B' && b=='A') return 0;
	if(a=='B' && b=='C') return 0;
	if(a=='C' && b=='B') return 0;
	if(a=='E' && b=='D') return 0;
	if(a=='D' && b=='E') return 0;
	return 1;
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1,s1,c2,s2;
	if(int((c1[0]-'0')*10+(c1[1]-'0'))!=int((c2[0]-'0')*10+(c2[1]-'0'))){
		cout<<0000;
		return 0;
	}
	if(int((s1[0]-'0')*10+(s1[1]-'0'))!=int((s2[0]-'0')*10+(s2[1]-'0'))){
		cout<<(s1[0]-'0')*10+(s1[1]-'0')<<" "<<(s2[0]-'0')*10+(s2[1]-'0')<<" ";
		cout<<1000;
		return 0;
	}
	if(f1(s1[2],s2[2])){
		cout<<1100;
		return 0;
	}
	if(f2(s1[2],s2[2])){
		cout<<1110;
		return 0;
	}else{
		cout<<1111;
		return 0;
	}
	
	return 0;
} 
