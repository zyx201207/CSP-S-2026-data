#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		printf("0000");
		return 0;
	}
	if(c1 == c2) printf("1");
	
	string h1, h2;
	h1 = s1[0]+s1[1];
	h2 = s2[0]+s2[1];
	if(h1 == h2){
		printf("1");
	}else if(h1 != h2){
		printf("000");
		return 0;
	}
	
	if( ( (s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C') ) || ( (s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E') ) ){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	
	char place1 = s1[2], place2 = s2[2];
	if(abs(int(place1)-int(place2) ) == 1){
		printf("1");
	}else{
		printf("0");
		return 0;
	}
	
	return 0;
}
