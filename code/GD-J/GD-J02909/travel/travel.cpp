#include<bits/stdc++.h>
using namespace std;
bool ck1(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C') return 1;
	}
	if(a=='D'||a=='F'){
		if(a=='D'||a=='F') return 1;
	}
	return 0;
}
bool ck2(char a,char b){
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='A') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='C'&&b=='B') return 1;
	if(a=='D'&&b=='F') return 1;
	if(a=='F'&&b=='D') return 1;
	return 0;
}
int main(){
	//¼ì²éfreopenÊÇ·ñ±»×¢ÊÍ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag1=1;
	if(c1==c2) cout<<1;
	else {
		cout<<0;
		flag1=0;
	}
	bool flag2=1;
	if(flag1&&s1[0]==s2[0]&&s1[1]==s2[1])  cout<<1;
	else{
		cout<<0;
		flag2=0;
	}
	if(flag1&&flag2&&ck1(s1[2],s2[2])) cout<<1;
	else cout<<0;
	if(flag1&&flag2&&ck2(s1[2],s2[2])) cout<<1;
	else cout<<0;
	return 0;
}
