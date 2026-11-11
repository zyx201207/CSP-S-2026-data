#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2) {	//che xiang
		cout<<1;
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {	//tong yi pai
			cout<<1;
			
			char a1=char(s1[2]);
			char a2=char(s2[2]);

			if(a1=='A') {
				if(a2=='B') {
					cout<<11;
				} else if(a2=='C') {
					cout<<10;
				} else {
					cout<<0<<0;
				}
			} else if(a1=='B') {
				if(a2=='A'||a2=='C') {
					cout<<11;
				} else {
					cout<<0<<0;
				}
			} else if(a1=='C') {
				if(a2=='B') {
					cout<<11;
				} else if(a2=='A') {
					cout<<10;
				} else {
					cout<<0<<0;
				}
			} else if(a1=='D') {
				if(a2=='F') {
					cout<<11;
				} else {
					cout<<0<<0;
				}
			} else {
				if(a2=='D') {
					cout<<11;
				} else {
					cout<<0<<0;
				}
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<0<<0<<0<<0;
	}
	//cout<<s1[0]<<' '<<s2[0]<<' '<<s1[1]<<' '<<s2[1]<<' '<<s1[2]<<' '<<s2[2]<<endl;
	return 0;
}
