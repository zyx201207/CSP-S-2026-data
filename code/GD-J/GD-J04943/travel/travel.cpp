#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
bool check(string a1,string b1){
	return ((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))||((a1[2]=='F'||a1[2]=='D')&&(b1[2]=='D'||b1[2]=='F')) ;
} 
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		bool f=0;
		cout<<1;
		if((a1[0]==b1[0])&&(a1[1]==b1[1])) cout<<1;
		else {
			cout<<0;
			f=1;
		}
		if(f) cout<<0;
		else {
			if(check(a1,b1)) cout<<1;
			else cout<<0;
		}
		if(f||(a1[2]=='D'&&b1[2]=='C')||(a1[2]=='C'&&b1[2]=='D')) cout<<0;
		else{
			if(((a1[2]=='F')&&(b1[2]=='D'))||((a1[2]=='D')&&(b1[2]=='F'))) cout<<1;
			else if(abs(int(a1[2])-int(b1[2]))==1) cout<<1;
			else cout<<0;
		}
		
	}
	return 0;
} 
