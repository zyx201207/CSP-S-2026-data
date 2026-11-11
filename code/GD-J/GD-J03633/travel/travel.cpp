#include<bits/stdc++.h>
using namespace std;
char sr[10],sx[10];
string cr,cx;
string a="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		a[0]='1';
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			a[1]='1';
			if((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='D'||sx[2]=='F')){
				cout<<a;
				return 0;
			}
			else if((sx[2]=='A'||sx[2]=='B'||sx[2]=='C')&&(sr[2]=='D'||sr[2]=='F')){
				cout<<a;
				return 0; 
			}
			else{
				if(sr[2]=='A'&&sx[2]=='C'){
					a[2]='1';
					cout<<a;
					return 0;
				}
				else if(sr[2]=='C'&&sx[2]=='A'){
					a[2]='1';
					cout<<a;
					return 0;
				}
				else{
					a[2]='1';
					a[3]='1';
					cout<<a;
					return 0;
				}
			}
		}
		else{
			cout<<a;
			return 0;
		}
	}
	else{
		cout<<a;
		return 0;
	}
	return 0;
}
