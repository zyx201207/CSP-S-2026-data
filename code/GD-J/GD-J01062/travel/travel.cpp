#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] and c1[1]==c2[1]){
		a=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		b=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B' or s2[2]=='C'){
			c=1;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A' or s2[2]=='C'){
			c=1;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='A' or s2[2]=='B'){
			c=1;
		}
	}else if(s1[2]=='D'){
		if(s2[2]=='F'){
			c=1;
		}
	}else if(s1[2]=='F'){
		if(s2[2]=='D'){
			c=1;
		}
	}
	if(c==0){
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			d=1;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A' or s2[2]=='C'){
			d=1;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='B'){
			d=1;
		}
	}
	else if(s1[2]=='D'){
		if(s2[2]=='F'){
			d=1;
		}
	}else if(s1[2]=='F'){
		if(s2[2]=='D'){
			d=1;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
