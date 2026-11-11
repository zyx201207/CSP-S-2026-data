#include <bits/stdc++.h>
using namespace std;

bool same_side(string s1,string s2){
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		return true;
	}
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		return true;
	}
	return false;
}

bool near(string s1,string s2){
	if(s1[2]=='A'&&s2[2]=='B') return true;
	if(s1[2]=='B'&&s2[2]=='A') return true;
	if(s1[2]=='B'&&s2[2]=='C') return true;
	if(s1[2]=='C'&&s2[2]=='B') return true;
	if(s1[2]=='F'&&s2[2]=='D') return true;
	if(s1[2]=='D'&&s2[2]=='F') return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int t1,t2;
	cin>>t1>>s1>>t2>>s2;
	if(t1==t2){
		cout << 1;
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout << 1;
			if(same_side(s1,s2)){
				cout << 1;
				if(near(s1,s2)){
					cout << 1;
				}else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}
	else cout << "0000";
	return 0;
}
