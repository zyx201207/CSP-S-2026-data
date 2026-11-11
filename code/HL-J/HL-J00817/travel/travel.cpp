#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	a=1;
	}
	if(a!=1){
		a=0;
		b=0;
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		b=1;
	}
	if(b!=1){
		b=0;
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			c=1;
		}
	}
	if(s1[2]=='A'){
		if(s2[2]=='C'){
			c=1;
		}
	}
	
	
	if(s1[2]=='B'){
		if(s2[2]=='C'){
			c=1;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'){
			c=1;
		}
	}
	
	
	if(s1[2]=='C'){
		if(s2[2]=='A'){
			c=1;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			c=1;
		}
	}
	
	
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			c=1;
		}
	}
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			c=1;
		}
	}
	if(c!=1){
		c=0;
	}
	
	
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			d=1;
		}
	}

	if(s1[2]=='B'){
		if(s2[2]=='C'){
			d=1;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'){
			d=1;
		}
	}
	
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			d=1;
		}
	}
	
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			d=1;
		}
	}
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			d=1;
		}
	}
	if(d!=1){
		d=0;
	}
	
	cout<<a<<b<<c<<d;
	return 0;
}