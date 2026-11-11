#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,c4,c1,c3;
	int a1=0,a2=0,a3=0,a4=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]==c3[0]&&c1[1]==c3[1]) {
		a1=1;
		if(c2[0]==c4[0]&&c2[1]==c4[1]) {
			a2=1;
			if(c2[2]>=68&&c2[2]<=70&&c2[2]!=69) {
				if(c4[2]>=68&&c4[2]<=70&&c4[2]!=69) {
					a3=1;
					a4=1;
				}
			}
			if(c2[2]>=65&&c2[2]<=67) {
				if(c4[2]>=65&&c4[2]<=67) {
					a3=1;
					if(c2[2]=='A'&&c4[2]=='B'||c2[2]=='B'&&c4[2]=='A'||c2[2]=='B'&&c4[2]=='C'||c2[2]=='C'&&c4[2]=='B') {
						a4=1;
					}
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
