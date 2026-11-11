#include <bits/stdc++.h>
using namespace std;
int seat[5];
void s(string se){
	if(se[2]=='A') seat[0]++;
	else if(se[2]=='B') seat[1]++;
	else if(se[2]=='C') seat[2]++;
	else if(se[2]=='D') seat[3]++;
	else seat[4]++;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,s1,r2,s2;
	cin>>r1>>s1>>r2>>s2;
	if(r1[0]!=r2[0]||r1[1]!=r2[1]) cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"000";
		else{
			cout<<"1";
			s(s1); s(s2);
			if(seat[0]+seat[1]+seat[2]==1&&seat[3]+seat[4]==1) cout<<"00";
			else{
				cout<<"1";
				if(seat[0]==1&&seat[2]==1) cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}
