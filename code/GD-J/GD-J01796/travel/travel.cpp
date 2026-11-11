#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
string a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m) {
		cout<<1;
		sum++;
		if(a[0]==b[0]&&a[1]==b[1]) {
			cout<<1;
			sum++;
			if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')) {
				cout<<1;
				sum++;
				char x=a[2],y=b[2];
				if(x=='A') {
					if(y=='B') {
						cout<<1;
						return 0;
					}
					cout<<0;
					return 0;
				}
				if(x=='B') {
					if(y=='A'||y=='C') {
						cout<<1;
						return 0;
					}
					cout<<0;
					return 0;
				}
				if(x=='C') {
					if(y=='B') {
						cout<<1;
						return 0;
					}
					cout<<0;
					return 0;
				}
			} 
			if((a[2]=='F'||a[2]=='D')&&(b[2]=='F'||b[2]=='D')) {
				cout<<1;
				sum++;
				char x=a[2],y=b[2];
				if(x=='F') {
					if(y=='D') {
						cout<<1;
						return 0;
					}
					cout<<0;
					return 0;
				}
				if(x=='D') {
					if(y=='F') {
						cout<<1;
						return 0;
					}
					cout<<0;
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=4-sum;i++) cout<<0;
	return 0;
}
