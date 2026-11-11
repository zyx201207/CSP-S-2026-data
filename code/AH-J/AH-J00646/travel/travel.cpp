#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	string c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1){cout<<"0000";return 0;}
	if(s1==c1){
		if(s2[0]!=c2[0]||s2[1]!=c2[1]){cout<<"1000";return 0;}
		char s=s2[2],c=c2[2];
		if(s2[2]<='C'&&c2[2]<='C'&&s2[1]==c2[1]&&s2[0]==c2[0]){
			if(s=='A'&&c!='B') {cout<<"1110";return 0;}
			else if(s=='B'&&c!='A'&&c!='C') {cout<<"1110";return 0;}
			else if(s=='C'&&c!='B') {cout<<"1110";return 0;}
			else if(s=='D'&&c!='F') {cout<<"1110";return 0;}
			else if(s=='F'&&c!='D') {cout<<"1110";return 0;}
			else {cout<<"1111";return 0;}
		}
		else if(s2[2]<='F'&&c2[2]<='F'&&c2[2]>='D'&&s2[2]>='D'&&s2[1]==c2[1]&&s2[0]==c2[0]){
			if(s=='A'&&c!='B') {cout<<"1110";return 0;}
			else if(s=='B'&&c!='A'&&c!='C') {cout<<"1110";return 0;}
			else if(s=='C'&&c!='B') {cout<<"1110";return 0;}
			else if(s=='D'&&c!='F') {cout<<"1110";return 0;}
			else if(s=='F'&&c!='D') {cout<<"1110";return 0;}
			else {cout<<"1111";return 0;}
		}
		cout<<"1100";
	}
	return 0;
}
