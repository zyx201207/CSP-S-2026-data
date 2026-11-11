#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int lens1 = s1.size(),lens2 = s2.size();
	if(c1 != c2) {
		printf("0000");
		return 0;
	}else {
		printf("1");
	}
	int p1 = 0,p2 = 0,l1 = 0,l2 = 0;

	for(int i = 0 ;i < lens1;i++) {
		if(i == lens1 - 1) {
			l1 = (s1[i] - 'A'); 
		}else{
			p1 = p1*10 + (s1[i] - '0'); 
		}
	}
	
	for(int i = 0 ;i < lens2;i++) {
		if(i == lens2 - 1) {
			l2 = (s2[i] - 'A'); 
		}else{
			p2 = p2*10 + (s2[i] - '0'); 
		}
	}
	//2 
	if(p1 == p2) {
		printf("1");
	}else {
		printf("0"); 
	}
	//3
	if(p1 == p2 && l1 <= 2 && l2 <= 2){
		printf("1");
	}else{
		printf("0");
	}
	//4
	if(p1 == p2 && (( l1 <= 2 && l2 <= 2 ) || (l1 > 2 && l2 > 2) ) && abs(l1 - l2) == 1) {
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
