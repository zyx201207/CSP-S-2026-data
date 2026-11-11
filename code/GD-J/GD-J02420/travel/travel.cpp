#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r2==x2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(r1==x1){
		cout<<1; 
		if(r2[1]==x2[1]&&r2[0]==x2[0]){
			cout<<1;
			if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
				if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
					cout<<1;
					if(r2[2]=='A'&&x2[2]=='C'){
						cout<<0;
					}
					if(r2[2]=='C'&&x2[2]=='A'){
						cout<<0;
					}
					else{
						cout<<1;
					}
				}
				else{
					cout<<0<<0;
				}
			}
			else{
				cout<<0<<0;
			}
			if(r2[2]=='F'||r2[2]=='D'){
				if(x2[2]=='D'||x2[2]=='F'){
					cout<<1<<1;
				}
				else{
					cout<<0<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}

	return 0;
} 
