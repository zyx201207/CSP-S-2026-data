#include<bits/stdc++.h>
using namespace std;
string s1, s2, t1, t2;
int a, b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	a=10*(s1[0]-'0')+(s1[1]-'0');
	b=10*(t1[0]-'0')+(t1[1]-'0');
	if(a==b) {
		printf("1");
		a=10*(s2[0]-'0')+(s2[1]-'0');
		b=10*(t2[0]-'0')+(t2[1]-'0');
		if(a==b) {
			printf("1");
			a=s2[2]-'A'+1;
			b=t2[2]-'A'+1;
			int f1=1, f2=1;
			if(a==4||a==5) f1=2;
			if(b==4||b==5) f2=2;
			if(f1==f2) {
				printf("1");
				if(a+1==b||a-1==b) {
					printf("1");
				}
				else {
					printf("0");
				}
			}
			else {
				printf("00");
			}
		}
		else {
			printf("000");
		}
	}
	else {
		printf("0000");
	}
	return 0;
}
