#include<iostream>
#include<string>
using namespace std;

bool beside_seat(char a,char b) {
	if(a=='A'&&b=='B') {
		return true;
	} else if(a=='B'&&b=='C') {
		return true;
	} else if(a=='D'&&b=='F') {
		return true;
	} else {
		swap(a,b);
		if(a=='A'&&b=='B') {
			return true;
		} else if(a=='B'&&b=='C') {
			return true;
		} else if(a=='D'&&b=='F') {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	printf("%d",(int)(c1==c2));
	int l1,l2;
	l1=(s1[0]-'0')*10+s1[1]-'0';
	l2=(s2[0]-'0')*10+s2[1]-'0';


	if((c1==c2)) {
		printf("%d",(int)(l1==l2));
		if (l1==l2) {

			bool rseatside=s1[2]=='D'||s1[2]=='F';
			bool xseatside=s2[2]=='D'||s2[2]=='F';
			if(rseatside==xseatside) {
				printf("1");
				if(beside_seat(s1[2],s2[2])) {
					printf("1");
				} else {
					printf("0");
				}
			} else {
				printf("00");
			}
		}else{
			printf("00");
		}
	} else {
		printf("000");
	}
}
