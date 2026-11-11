#include <bits/stdc++.h>
using namespace std;
int a,b;
string a_1,b_1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a_1>>b>>b_1;
	if(a==b){
		cout<<"1";
		if(a_1[0]==b_1[0]&&a_1[1]==b_1[1]){
			cout<<"1";
			if(a_1[2]=='A'||a_1[2]=='B'||a_1[2]=='C'&&b_1[2]=='A'||b_1[2]=='B'||b_1[2]=='C'){
				cout<<"1";
				if(a_1[2]=='A'&&b_1[2]=='B'||a_1[2]=='B'&&b_1[2]=='C'||a_1[2]=='B'&&b_1[2]=='A'||a_1[2]=='C'&&b_1[2]=='B'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else{
				if(a_1[2]=='D'||a_1[2]=='F'&&b_1[2]=='D'||b_1[2]=='F')
				{
					cout<<"11";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

