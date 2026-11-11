#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
set<char> s;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	s.insert('A');
	s.insert('B');
	s.insert('C');
	char a1,a2;
	if(s1[2] < s2[2]){
		a1 = s1[2];
		a2 = s2[2];
	}else{
		a1 = s2[2];
		a2 = s1[2];
	}
	//cout<<a1<<" "<<a2;
	if(c1 == c2){
		printf("1");
		if(s1[0] == s2[0] and s1[1] == s2[1]){
			printf("1");
			if(s.count(s1[2]) != s.count(s2[2])){
				printf("00");
			}else{
				printf("1");
				if((a1=='A' and a2=='B') or (a1=='B' and a2=='C') or (a1=='D' and a2=='F')){
					printf("1");
				}else{
					printf("0");
				}
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
