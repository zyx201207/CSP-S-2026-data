#include<bits/stdc++.h>
using namespace std;
string a[7];
int b[2];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++) {
		cin>>a[i];		
	}			
	if(a[0][0]==a[2][0]&&a[0][1]==a[2][1]) {
		cout<<'1';		
		if(a[1][0]==a[3][0]&&a[1][1]==a[3][1]) {
			cout<<'1';
			if(a[1][2]<='c'&&a[3][2]<='c'||a[1][2]>='D'&&a[3][2]>='D') {
				cout<<'1';
				if(a[1][2]=='A'&&a[3][2]=='B'||a[1][2]=='B'&&a[3][2]=='A'||a[1][2]=='B'&&a[3][2]=='C'||a[1][2]=='C'&&a[3][2]=='B'||a[1][2]=='D'&&a[3][2]=='F'||a[1][2]=='F'&&a[3][2]=='D')
					cout<<'1';
				else
					cout<<'0';
			}
			else {
				cout<<'0';
			}			
		}
		else
			cout<<'0';
	}
	else
		cout<<'0';
	return 0;
}
