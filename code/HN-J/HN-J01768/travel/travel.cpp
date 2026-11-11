#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a,b,c,d;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 == c1){
		a=1;
		if((s2[0]+s2[1])+'0' == (c2[0]+c2[1])+'0'){
			b=1;
			if((s2[2]>='A'&&s2[2]<='C') && !(c2[2]>='D'&&c2[2]<='E') || (c2[2]>='A'&&c2[2]<='C') && !(s2[2]>='D'&&s2[2]<='E')){
				c=1; 
				if(abs(s2[2]-c2[2])==1){
	 				d=1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
