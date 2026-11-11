#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int b1=0,b2=0,b3=0,b4=0;
	cin >> c1>> s1>> c2>> s2;
	if(c1==c2) {
		b1=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			b2=1;
			if((s1[2]-64)<=3 && (s1[2]-64)>=1 && (s2[2]-64)<=3 && (s2[2]-64)>=1){
				b3=1;
				if((s1[2]+1==s2[2] || s1[2]-1==s2[2] || s1[2]+s2[2]!='F'+'D') && s1[2]+s2[2]!='C'+'D'){
					b4=1;
				}
			}
		}
	}
	cout << b1<< b2<< b3<< b4;
	return 0;
}
