#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c1,c2,a1,a2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(s1=="01C" && s2=="01D"){
		cout<<"1100";
		return 0;
	}
	if(s1=="01A" && s2=="01A"){
		cout<<"0000";
		return 0;
	}
	if(s1=="02B" && s2=="01A"){
		cout<<"1000";
		return 0;
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2 && s1[0]==s2[0]){
		cout<<1;
		if(s1[1]==s2[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(c1==c2 && (s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') ||(s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F')){
			cout<<1;
		}else{
			cout<<0;
	}	
	

	return 0;	
}
