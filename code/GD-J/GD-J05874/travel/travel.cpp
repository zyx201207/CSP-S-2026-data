#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char r=s1[2],w=s2[2];
	int a=0,b=0,c=0,d=0;
	if(c1==c2){
		    a=1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
		    b=1;
		    if(r=='D' and w=='F' or r=='A' and w=='B' or r=='B' and w=='C'){
		        c=1;
		        d=1;
	        }else if(r=='A' and w=='C'){
		        c=1;
	        }
        }
	}
	cout << a << b << c << d;
	
	return 0;
} 
