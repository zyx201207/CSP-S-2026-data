#include<bits/stdc++.h>
using namespace std;
long long c1,c2,s,x;
char s1,x1;
long long a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s>>s1>>c2>>x>>x1;
	if(c1==c2){
		a=1;
		if(s==x){
			b=1;
			if(s1=='A'||s1=='B'||s1=='C'&&x1=='A'||x1=='B'||x1=='C'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else if(s1=='D'&&x1=='F'||s1=='F'&&x1=='D'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else{
				c=0;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
		}
		else{
			b=0;
			if(s1=='A'||s1=='B'||s1=='C'&&x1=='A'||x1=='B'||x1=='C'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else if(s1=='D'&&x1=='F'||s1=='F'&&x1=='D'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else{
				c=0;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
		}
	}
	else{
		a=0;
		if(s==x){
			b=1;
			if(s1=='A'||s1=='B'||s1=='C'&&x1=='A'||x1=='B'||x1=='C'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else if(s1=='D'&&x1=='F'||s1=='F'&&x1=='D'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else{
				c=0;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
		}
		else{
			b=0;
			if(s1=='A'||s1=='B'||s1=='C'&&x1=='A'||x1=='B'||x1=='C'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else if(s1=='D'&&x1=='F'||s1=='F'&&x1=='D'){
				c=1;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
			else{
				c=0;
				if(s1=='A'&&x1=='B'){
					d=1;
				}
				else if(s1=='B'&&x1=='A')	d=1;
				else if(s1=='B'&&x1=='C')	d=1;
				else if(s1=='C'&&x1=='B')	d=1;
				else if(s1=='D'&&x1=='F')	d=1;
				else if(s1=='F'&&x1=='D')	d=1;
				else{
					d=0;
				}
			}
		}
	}
	if(a==0){
		b=0;
	}
	if(b==0){
	 	c=0;
	 	d=0;
	}
	cout<<a<<b<<c<<d;
}