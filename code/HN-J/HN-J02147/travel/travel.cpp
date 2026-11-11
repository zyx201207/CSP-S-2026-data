#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,d=0,e=0;
	string s,x,c,f;
	cin>>c>>s>>f>>x;
	if(c[1]==f[1]){
		a=1;
		if(c[1]!=f[1]){
			a=0;
		}
	}
	if(s[1]==x[1]){
		b=1;
		if(s[1]!=x[1]) {
			b=0;
		}
		
	}
	if(s[1]==x[1]){
		if (s[2] && x[2]=='A'||'B'||'C'){
			d=1;
		}
			if (s[2] && x[2]=='D'||'F'){
			d=1;
		}
			else {
				d=0;
			}
	}
	if(s[2]=='A' || x[2]=='B'){
		e=1;
		if(s[2]=='B' || x[2]=='C'){
			e=1;
			if(s[2]=='A' || x[2]=='B'){
				e=1;
				if(s[2]=='A' || x[2]=='B'){
					e=1;
		
				}
				else{
					e=0;
				}
			}
		}		
	}
	cout<<a<<b<<d<<e;
	return 0;
}
