#include<bits/stdc++.h>//´æE: 
using namespace std;
//completed
string c1,c2,s1,s2;
bool ss(char s1,char s2) {
	return (s1=='D' && s2=='E') ||
	       (s1=='E' && s2=='D') ||
	       (s1!='E' && s1!='D' && s2!='D' && s2!='E');
}
bool tg(char s1,char s2){
	return (s1=='D' && s2=='E') ||
	       (s1=='E' && s2=='D') ||
	       (s1=='A' && s2=='B') ||
	       (s1=='B' && s2=='A') ||
		   (s1=='B' && s2=='C') ||
		   (s1=='C' && s2=='B');
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			cout<<1;
			if(ss(s1[2],s2[2])) {
				cout<<1;
				if(tg(s1[2],s2[2])){
					cout<<1;
					return 0;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		} else {
			cout<<"000";
			return 0;
		}
	} else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
