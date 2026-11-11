#include <bits/stdc++.h>
using namespace std;
int n1,n2,n3,n4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		n1=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			n2=1;
			if((s1[2]>='D' && s2[2]>='D') || (s1[2]<'D' && s2[2]<'D')){
				n3=1;
				if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))n4=1;
				if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A'))n4=1;
				if((s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B'))n4=1;
			}
		}
	}
	cout << n1 << n2 << n3 << n4;
	return 0;
} 
