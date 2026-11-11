//遵义汇川区周林 陈俊洁 GZ-J00342
#include <bits/stdc++.h>
using namespace std;
string s1,c1;
string s2,c2;
int op1=1,op2=1,op3=1,op4=1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	int lenc=c1.size();
	int lens=s1.size();
	for(int i=0; i<lens; i++) {
		if(s1[i]!=s2[i]) {
			op1=0;
			break;
		}
	}
	if(op1==0) {
		op2=0;
		op3=0;
		op4=0;
	} else {
		for(int i=0; i<lenc-1; i++) {
			if(c1[i]!=c2[i]) {
				op2=0;
				break;
			}
		}
		if(op2==0){
			op3=0;
			op4=0;
		}
		else {
			if(c1[lenc-1]=='A'||c1[lenc-1]=='B'||c1[lenc-1]=='C') {
				if(c2[lenc-1]=='D'||c2[lenc-1]=='F') op3=0;
			} else if(c1[lenc-1]=='D'||c1[lenc-1]=='F') {
				if(c2[lenc-1]=='A'||c2[lenc-1]=='B'||c2[lenc-1]=='C') op3=0;
			}
		}
		if(op3==0) op4=0;
		else {
			if(c1[lenc-1]=='A'&&c2[lenc-1]!='B') {
				op4=0;
			}
			if(c1[lenc-1]=='B'&&(c2[lenc-1]!='A'||c2[lenc-1]!='C')) {
				op4=0;
			}
			if(c1[lenc-1]=='C'&&c2[lenc-1]!='B') {
				op4=0;
			}
			if(c1[lenc-1]=='D'&&c2[lenc-1]!='F') {
				op4=0;
			}
			if(c1[lenc-1]=='F'&&c2[lenc-1]!='D') {
				op4=0;
			}
		}
	}
	cout<<op1<<op2<<op3<<op4;
	return 0;
}

