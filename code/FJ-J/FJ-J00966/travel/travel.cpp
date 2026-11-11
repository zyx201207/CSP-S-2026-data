//CSP-J 1-travel
#include<bits/stdc++.h>
using namespace std;
int p1,p2;
string s1,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>p1>>s1>>p2>>s2;
	if(p1!=p2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	if(min(c1,c2)=='D'&&max(c1,c2)=='F'){
		cout<<"1111";
		return 0;
	}
	if(abs(c2-c1)>=3){
		cout<<"1100";
		return 0;
	}
	if(abs(c2-c1)==2&&min(c1,c2)>'A'){
		cout<<"1100";
		return 0;
	}
	if(min(c1,c2)=='C'&&max(c1,c2)=='D'){
		cout<<"1100";
		return 0;
	}
	if(abs(c2-c1)==2&&min(c1,c2)=='A'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
