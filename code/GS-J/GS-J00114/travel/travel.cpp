#include<bits/stdc++.h>
using namespace std;
char a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a1>>b1>>c1>>d1>>e1>>a2>>b2>>c2>>d2>>e2;
	//printf("%c %c %c %c %c %c %c %c %c %c\n",a1,b1,c1,d1,e1,a2,b2,c2,d2,e2);
	
	if(a1==a2 && b1==b2){
		a=1;
		if(c1==c2 && d1==d2){
			b=1;
			if(e1=='A'){
				if(e2=='B'){
					c=1;
					d=1;
				}
				else if(e2=='C'){
					c=1;
				}
			}
			if(e1=='B'){
				if(e2=='A' || e2=='C'){
					c=1;
					d=1;
				}
			}
			if(e1=='C'){
				if(e2=='B'){
					c=1;
					d=1;
				}
				else if(e2=='A'){
					c=1;
				}
			}
			if(e1=='D'){
				if(e2=='F'){
					c=1;
					d=1;
				}
			}
			if(e1=='F'){
				if(e2=='D'){
					c=1;
					d=1;
				}
			}
		}
	}
	
	cout<<a<<b<<c<<d;
	
	return 0;
}
