#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string s1,s2;
signed main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if (a==b) {
		printf("1");
		if (s1[0]==s2[0]&&s1[1]==s2[1]) {
			printf("1");
			if ((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) {
				printf("1");
				if (min(s1[2],s2[2])+1==max(s1[2],s2[2])&&min(s1[2],s2[2])!='C') {
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
	fclose(stdin);
	fclose(stdout);
}
