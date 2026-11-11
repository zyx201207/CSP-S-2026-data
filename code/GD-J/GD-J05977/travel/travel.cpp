#include<bits/stdc++.h>
using namespace std;

int main(){
	string c1,s1,c2,s2;
	freopen("travel.in","r",stdin);
	cin>>c1>>s1>>c2>>s2;
	int a=1,b=1,c=1,d=1;
	if(c1!=c2){
		a=0;
		b=0;
		c=0;
		d=0;
	}
	if(s1.substr(0,2)!=s2.substr(0,2)){
		b=0;
		c=0;
		d=0;
	}
	string p1=s1.substr(2,1),p2=s2.substr(2,1);
	int r1=0,r2=0;
	if(p1=="D" || p1=="F")	r1=1;
	if(p2=="D" || p2=="F")	r2=1;
	if(r1!=r2){
		c=0;
		d=0;
	}
	if((p1=="A" && p2=="C") || (p2=="A" && p1=="C"))	d=0;
	
	
	freopen("travel.out","w",stdout);
	cout<<a<<b<<c<<d;
	fclose(stdout);
}
