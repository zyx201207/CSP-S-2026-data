#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2;
string s1,s2;
bool check(char x,char y) {
	if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')) return true;
	else return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		printf("0000\n");
		return 0;
	}
	printf("1");
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		printf("1");
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) {
			printf("1");
			if(check(s1[2],s2[2])||check(s2[2],s1[2])) {
				printf("1\n");
				return 0;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else {
			printf("00\n");
			return 0; 
		}
	}
	else {
		printf("000\n");
		return 0;
	}
	return 0;
}
