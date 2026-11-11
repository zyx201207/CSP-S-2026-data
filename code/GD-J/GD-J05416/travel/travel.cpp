#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b>>c>>d;
	if(a == c){
		e[0]='1';
		if(b[0]==d[0]&&b[1] ==d[1]){
			e[1]='1';
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
				e[2]='1';
				if(b[2]=='B'||d[2]=='B'){
					e[3]='1';
				}
				else{
					e[3]='0';
				}
				
			}
			else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				e[2]='1';
				e[3]='1';
			}
			else{
				e[2]='0';
				e[3]='0';
			}
			
		}
		else{
			e[1]='0';
			e[2]='0';
			e[3]='0';
		}
	}
	else if (a!=c){
		e[0]='0';
		e[1]='0';
		e[2]='0';
		e[3]='0';
	}
	cout << e[0]<<e[1]<<e[2]<<e[3];
}


