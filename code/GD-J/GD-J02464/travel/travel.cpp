#include<bits/stdc++.h>
using namespace std;

int c1,c2;
int s1,s2;
char p1,p2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
	if(c1==c2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(p1=='A' && p2=='B') cout<<"11";
	else if(p1=='B' && p2=='A') cout<<"11";
	else if(p1=='A' && p2=='C') cout<<"10";
	else if(p1=='C' && p2=='A') cout<<"10";
	else if(p1=='B' && p2=='C') cout<<"11";
	else if(p1=='C' && p2=='B') cout<<"11";
	else if(p1=='D' && p2=='E') cout<<"11";
	else if(p1=='E' && p2=='D') cout<<"11";
	else cout<<"00";
	return 0;
}
