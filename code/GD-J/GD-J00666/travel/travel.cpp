#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int w1,w2;
	string s1,s2;
	cin>>w1>>s1>>w2>>s2;
	if(w1==w2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(int(10*s1[0])+int(s1[1])==int(10*s2[0])+int(s2[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D')||(s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[1]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[1]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[1]=='D')) cout<<1;
	else cout<<0;
	return 0;
} 
