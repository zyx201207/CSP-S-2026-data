#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	freopen("travel.in","r",stdin);
	int i=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		freopen("travel.out","W",stdout);
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			freopen("travel.out","W",stdout);
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				freopen("travel.out","W",stdout);
				cout<<1;
				if(s1[2]=='B'||s2[2]=='B'){
					freopen("travel.out","W",stdout);
					cout<<1;
				}
				else {
					freopen("travel.out","W",stdout);
					cout<<0;
				}
			}
			else if(s1[2]>'C'&&s2[2]>'C'){
				freopen("travel.out","W",stdout);
				cout<<11;
			}
			else{
				freopen("travel.out","W",stdout);
				cout<<"00";
			} 
		}
		else{
		freopen("travel.out","W",stdout);
			cout<<"000";
		}
	}
	freopen("travel.out","W",stdout);
		cout<<"0000";
		
	return 0;
} 
