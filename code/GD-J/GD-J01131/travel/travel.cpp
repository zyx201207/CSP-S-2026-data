#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int p1,p2,q1,q2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p1>>s1>>p2>>s2;
	if(p1==p2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	q1=(s1[0]-'0')*10+(s1[1]-'0');
	q2=(s2[0]-'0')*10+(s2[1]-'0');
	if(q1==q2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	a=s1[2];
	b=s2[2];
	if((a=='F' && b=='D') || (a=='D' && b=='F')){
		cout<<"1";
	}else if((a=='C' && b=='B') || ((a=='B' && b=='C'))){
		cout<<"1";
	}else if((a=='A' && b=='B') || ((a=='B' && b=='A'))){
		cout<<"1";
	}else if((a=='C' && b=='A') || (a=='A' && b=='C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((a=='F' && b=='D') || (a=='D' && b=='F')){
		cout<<"1";
	}else if((a=='C' && b=='B') || ((a=='B' && b=='C'))){
		cout<<"1";
	}else if((a=='A' && b=='B') || ((a=='B' && b=='A'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
