#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool cmp(char a,char b){
	if (a=='A' || a=='B' || a=='C'){
		return b=='D' || b == 'F';
	}
	else return b == 'A' || b=='B' || b == 'C';
}
bool beside(char a,char b){
	if (a=='A'){
		return b=='B';
	}
	else if (a=='B') return b=='A' || b=='C';
	else if (a=='C') return b=='B';
	else if (a=='D') return b=='F';
	else if (a=='F') return b=='D';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if (s1!=s3){
		cout<<"0000";
		
	}
	else {
		cout<<"1";
		if (s2[0] != s4[0] || s2[1] != s4[1]){
			cout<<"000";
		}
		else {
			cout<<"1";
			if (cmp(s2[2],s4[2])) {
				cout<<"00";
			}
			else {
				cout<<"1";
				if (beside(s2[2],s4[2])) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
} 
