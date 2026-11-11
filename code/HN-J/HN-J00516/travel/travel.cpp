#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a=0,b=0,c=0,d=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b++;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		        c++;
		        if(s1[2]=='A'&&s2[2]=='B'){
		        	d++;
				}
				else if(s1[2]=='B'&&s2[2]=='C'){
		        	d++;
				}
				else if(s1[2]=='D'&&s2[2]=='E'){
		        	d++;
				}
				else if(s1[2]=='B'&&s2[2]=='A'){
		        	d++;
				}
				else if(s1[2]=='C'&&s2[2]=='B'){
		        	d++;
				}
				else if(s1[2]=='E'&&s2[2]=='D'){
		        	d++;
				}
	        }
		}
	}
	cout<<a<<b<<c<<d;
		
	return 0;
} 
