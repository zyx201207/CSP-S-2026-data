#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a1=0,a2=0,a3=0,a4=0;
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i<=s1.size();i++){
		for(int j = 0;j<=s2.size();j++){
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				a2=1;
			}
			if(s1[2]=='A'&&s2[2]=='B'){
				a3=1;
				a4=1;
			}
			if(s1[2]=='A'&&s2[2]=='C'){
				a3=1;
			}
			if(s1[2]=='A'&&s2[2]=='D'){
				a3=0;
			}
			if(s1[2]=='A'&&s2[2]=='F'){
				a3=0;
			}
			//
			if(s1[2]=='B'&&s2[2]=='A'){
				a3=1;
				a4=1;
			}
			if(s1[2]=='B'&&s2[2]=='C'){
				a3=1;
				a4=1;
			}
			if(s1[2]=='B'&&s2[2]=='D'){
				a3=0;
			}
			if(s1[2]=='B'&&s2[2]=='F'){
				a3=0;
			}
			//
			if(s1[2]=='C'&&s2[2]=='A'){
				a3=1;
			}
			if(s1[2]=='C'&&s2[2]=='B'){
				a3=1;
				a4=1;
			}
			if(s1[2]=='C'&&s2[2]=='D'){
				a3=0;
			}
			if(s1[2]=='C'&&s2[2]=='F'){
				a3=0;
			}
			//
			if(s1[2]=='D'&&s2[2]=='A'){
				a3=0;
			}
			if(s1[2]=='D'&&s2[2]=='B'){
				a3=0;
			}
			if(s1[2]=='D'&&s2[2]=='C'){
				a3=0;
			}
			if(s1[2]=='D'&&s2[2]=='F'){
				a3=1;
				a4=1;
			}
			//
			if(s1[2]=='F'&&s2[2]=='A'){
				a3=0;
			}
			if(s1[2]=='F'&&s2[2]=='B'){
				a3=0;
			}
			if(s1[2]=='F'&&s2[2]=='C'){
				a3=0;
			}
			if(s1[2]=='F'&&s2[2]=='D'){
				a3=1;
				a4=1;
			}
			
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				a2=1;
			}
			else{
				a2=a3=a4=0;
			}
		}
	}
	if(c1==c2){
		a1 = 1;
	}
	else{
		a1 = a2 = a3 = a4 = 0;
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}
