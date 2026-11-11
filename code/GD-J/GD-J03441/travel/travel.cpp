#include <bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if(a=='A' || a=='B' || a=='C'){
		if(b=='A' || b=='B' || b=='C')return 1;
	}
	if(a=='D' || a=='F'){
		if(b=='D' || b=='F')return 1;
	}
	return 0;
}
bool check2(char a,char b){
	if(a=='A' && b=='B')return 1;
	if(a=='B' && b=='A')return 1;
	if(a=='B' && b=='C')return 1;
	if(a=='C' && b=='B')return 1;
	if(a=='D' && b=='F')return 1;
	if(a=='F' && b=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<'1';
			if(check1(s1[2],s2[2])){
				cout<<'1';
				if(check2(s1[2],s2[2])){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
