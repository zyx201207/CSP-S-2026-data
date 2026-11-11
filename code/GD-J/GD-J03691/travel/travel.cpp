#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int x,x1,x2,x3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a[0]==b[0]&&a[1]==b[1]){
		x=1;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			x1=1;
			if(a1[2]<='C'&&b1[2]<='C'){
				x2=1;
				if(a1[2]=='A'&&b1[2]=='B'){
					x3=1;
				}
				else if(a1[2]=='B'&&b1[2]=='A'){
					x3=1;
				}
				else if(a1[2]=='B'&&b1[2]=='C'){
					x3=1;
				}
				else if(a1[2]=='C'&&b1[2]=='B'){
					x3=1;
				}
				else if(a1[2]=='D'&&b1[2]=='F'){
					x3=1;
				}
				else if(a1[2]=='F'&&b1[2]=='D'){
					x3=1;
				}
			}
			else if(a1[2]>'C'&&a1[2]<='F'&&b1[2]>'C'&&b1[2]<='F'){
				x2=1;
				if(a1[2]=='A'&&b1[2]=='B'){
					x3=1;
				}
				else if(a1[2]=='B'&&b1[2]=='A'){
					x3=1;
				}
				else if(a1[2]=='B'&&b1[2]=='C'){
					x3=1;
				}
				else if(a1[2]=='C'&&b1[2]=='B'){
					x3=1;
				}
				else if(a1[2]=='D'&&b1[2]=='F'){
					x3=1;
				}
				else if(a1[2]=='F'&&b1[2]=='D'){
					x3=1;
				}
			}
	   }
	}
	cout<<x<<x1<<x2<<x3;
	return 0;
} 
