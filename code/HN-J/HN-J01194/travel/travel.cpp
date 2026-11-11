#include <bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int n1,n2,n3,n4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1==b1){
		n1=1;
	}
	if(a[0]==b[0] && a[1]==b[1]){
		n2=1;
	}
	if(a[2]=='A'){
		if(b[2]=='B'){
			n3=1;
			n4=1;
		}
		else if(b[2]=='C'){
			n3=1;
		}
	}
	if(a[2]=='B'){
		if(b[2]=='A'){
			n3=1;
			n4=1;
		}
		else if(b[2]=='C'){
			n3=1;
			n4=1;
		}
	}
	if(a[2]=='C'){
		if(b[2]=='B'){
			n3=1;
			n4=1;
		}
		else if(b[2]=='A'){
			n3=1;
		}
	}
	if(a[2]=='D'){
		if(b[2]=='F'){
			n3=1;
			n4=1;
		}
	}
	if(a[2]=='F'){
		if(b[2]=='D'){
			n3=1;
			n4=1;
		}
	}
	if(n1==1){
		if(n2==1){
			if(n3==1){
				if(n4==1){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
