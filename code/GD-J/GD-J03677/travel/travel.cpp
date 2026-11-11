#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2; 
    if(c1==c2)a=1;
    if(a&&s1[0]==s2[0]&&s1[1]==s2[1])b=1;
    if(b){
    	if(s1[2]=='A'){
    		if(s2[2]=='B'||s2[2]=='C')c=1;
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C')c=1;
		}
		if(s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B')c=1;
		}
		if(s1[2]=='D'){
			if(s2[2]=='F')c=1;
			d=1;
		}
		if(s1[2]=='F'){
			if(s2[2]=='D'){
				c=1;
				d=1;
			}
		}
	}
	if(c){
		if(abs(s1[2]-s2[2])==1){
			d=1;
		}
	}
	if(a)cout << 1;
	else cout << 0;
	if(b)cout << 1;
	else cout << 0;
	if(c)cout << 1;
	else cout << 0;
	if(d)cout << 1;
	else cout << 0;
	return 0;
} 
