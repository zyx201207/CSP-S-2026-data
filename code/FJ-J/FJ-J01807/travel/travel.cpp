#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cr,cx;
	int chr,chx;
	char sr,sx;
	cin>>cr>>chr>>sr>>cx>>chx>>sx;
	if(cr==cx){
		cout<<"1";
		if(chr==chx){
			cout<<"1";
			if((('A'==sr||sr=='B'||sr=='C')&&('A'==sx||sx=='B'||sx=='C'))||(('D'==sr||sr=='F')&&('D'==sx||sx=='F'))){
				cout<<"1";
				if(abs(sr-sx)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
