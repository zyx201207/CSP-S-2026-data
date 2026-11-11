#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int abs1(int x,int y) {
	if(x>=y) {
		return x-y;
	} else {
		return y-x;
	}
}
int main() {
	int t1,t2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool cnt=false;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0; i<2; i++) {
		if(c1[i]!=c2[i]) {
			cnt=true;
		}
	}
	if(cnt==true) {
		cout<<"0000";
	} else {
		cnt=false;
		for(int i=0; i<2; i++) {
			if(s1[i]!=s2[i]) {
				cnt=true;
			}
		}//1ее
		if(cnt==true) {
			cout<<"1000";
		} else {
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')) {
				cout<<"1100";
			} else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')) {
				cout<<"1100";
			} else {
				int a=s1[2]-'A',b=s2[2]-'A';
				int t=abs1(a,b);
				//cout<<s1[0]<<" "<<s1[1]<<" "<<s1[2]<<endl;
				if(t==1) {
					cout<<"1111";
				} else {
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
