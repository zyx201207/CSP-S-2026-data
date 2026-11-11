#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[4]= {0,0,0,0};
	if(c1==c2) {
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			a[1]=1;
			char x=s1[3],y=s2[3];
			if(((x=='A'||x=='B'||x=='C')&&(y!='D'||y!='F'))||((y=='A'||y=='B'||y=='C')&&(x!='D'||x!='F'))||((x!='A'||x!='B'||x!='C')&&(y=='D'||y=='F'))||((y!='A'||y!='B'||y!='C')&&(x=='D'||x=='F'))) {
				a[2]=1;
				if(((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))||((x=='D'||x=='F')&&(y=='D'||y=='F'))) {
					a[3]=1;
				}
			}
		}
	}
	for(int i=0; i<4; i++) {
		cout<<a[i];
	}
	return 0;
}
