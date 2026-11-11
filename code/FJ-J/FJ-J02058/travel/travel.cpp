#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s1;
	int a,b=0,c=0,d=0;
	
	if(c1==1||c1==16||c2==1||c2==16){
		a=0;
	}
	else{
		if (c1==c2){
	    	a=1;
		}
		else{
			a=0;
			}
	} 
	
	if (s1==s2){
	    	b=1;
		}
		else{
			b=0;
			}
	    	
	cout << a << b << c << d;
	
	return 0;
}
