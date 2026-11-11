#include<bits/stdc++.h>
using namespace std;
int num1,num2;
char o1,o2;
int main() {
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
		for(int i=0; i<s1.size(); i++) {
			if(isdigit(s1[i])) {
				num1=num1*10+s1[i]-'0';
			} else o1=s1[i];
		}
		for(int i=0; i<s2.size(); i++) {
			if(isdigit(s2[i])) {
				num2=num2*10+s2[i]-'0';
			} else o2=s2[i];
		}
		if(num1==num2) {
			cout<<1;
			if(o1=='A'&&o2=='B'||o1=='A'&&o2=='C'||o1=='B'&&o2=='C'||o1=='D'&&o2=='F'||
			        o1=='B'&&o2=='A'||o1=='C'&&o2=='A'||o1=='C'&&o2=='B'||o1=='F'&&o2=='D') {
				cout<<1;
				if(!(o1=='A'&&o2=='C'||o1=='C'&&o2=='A')) {
					cout<<1;
				} else cout<<"0";
			} else cout<<"00";
		} else cout<<"000";
	} else cout<<"0000";
	return 0;
}

