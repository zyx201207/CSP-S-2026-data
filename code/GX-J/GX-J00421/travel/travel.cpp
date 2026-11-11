#include<bits/stdc++.h>
using namespace std;
string n,a,m,b;
int c[10];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n[0]==m[0]&&n[1]==m[1]) {
		c[0]=1;
		if(a[0]==b[0]&&a[1]==b[1]) {
			c[1]=1;
			if((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C')) {
				c[2]=1;
				if(a[2]-b[2]==1||b[2]-a[2]==1) {
					c[3]=1;
				} else {
					c[3]=0;
				} 
			} else {
				c[2]=c[3]=0;
			}
		} else {
			c[1]=c[2]=c[3]=0;
		}
	} else {
		c[0]=c[1]=c[2]=c[3]=0;
	}
	cout<<c[0]<<c[1]<<c[2]<<c[3];
	return 0;
}
