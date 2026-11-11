#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if((c1 == c2) && (c1 != "01" && c1 != "16")){
		cout << 1;
		if(s1[0,1] == s2[0,1]){
			cout << 1;
			if((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='A'&&s2[2]=='C') || (s1[2]=='B'&&s2[2]=='C') || 
			(s1[2]=='B'&&s2[2]=='A') || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='C'&&s2[2]=='A') || 
			(s1[2]=='D'&&s2[2]=='E') || (s1[2]=='E'&&s2[2]=='D')){
			 	cout << 1;
			 	if((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&s2[2]=='C') || (s1[2]=='B'&&s2[2]=='A') ||
				(s1[2]=='C'&&s2[2]=='B') || (s1[2]=='D'&&s2[2]=='E') || (s1[2]=='E'&&s2[2]=='D')){
					cout << 1;
				}
				else{
					cout << 0;
				}
			 }
			 else {
			 	cout << 0;
			 }
		}
		else{
			cout << 0;
		}
	} 
	else{
		cout << 0;
	}
} 
