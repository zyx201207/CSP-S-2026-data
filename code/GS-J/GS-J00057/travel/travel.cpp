#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a = 1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b = 1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					c = 1;
				}
		
			}
			else if(s1[2]=='D'||s1[2]=='F' ){
				if(s1[2]=='D'||s1[2]=='F'){
					c = 1;
				}
		
			}
			else{
				c= 0;
			}
			if(s1[2]-s2[2]<=1){
		
				if(s1[2]=='C'&&s2[2]=='D'){
					d= 0;
				}
				else{
					d = 1;
				}
		
			}
			else{
				d = 0;
				}
		}
		else{
			b = 0;
		}
	}
	else{
		a=0;
	}
	
	
	
	cout << a  << b << c  << d;
	return 0;
}
