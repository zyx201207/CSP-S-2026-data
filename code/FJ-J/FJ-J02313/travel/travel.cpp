#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		a = 1;
		if(s1 != s2){
			b = 1;
			if(s1 >= 'A' && s1 <= 'C' && s2 >= 'A' && s2 <= 'C' || s1 >= 'C' && s1 <= 'F' && s2 >= 'C' && s1 <= 'F'){
				c = 1;
				if(s1 - s2 == 1 && s2 - s1 == 1){
					d = 1;
				}else{
					d = 0;
				}
			}else{
				c = 0;
			}
		}else{
			b = 0;
		} 
	}else{
		a = 0;
	} 
	if(c1 != c2){
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	} 
	cout << a << b << c << d;
	return 0;
}

