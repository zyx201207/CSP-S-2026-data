#include<iostream>
#include<cstring>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b2;
	string s1,s2;
	cin>>a1>>s1;
	cin>>b2>>s2;
	bool j=0,q=0,k=0,ace=0;
	if(a1==b2)
		j=1;
	string h1,h2;
	s1[0]=h1[0];
	s1[1]=h1[1];
	s2[0]=h2[0];
	s2[1]=h2[1];
	if(j==1&&h1==h2)
		q=1;
	char o1,o2;
	o1=s1[2];//ab bc ac df
	o2=s2[2];//ab bc df
	if(q==1){	
		if(o1=='A'){
			if(o2=='B'){
				k=1;
				ace=1;
			}
			if(o2=='C'){
				k=1;
			}
		}
		if(o1=='B'){
			if(o2=='A'){
				k=1;
				ace=1;
			}
			if(o2=='C'){
				k=1;
				ace==1;
			}
		}
		if(o1=='C'){
			if(o2=='A'){
				k=1;
			}
			if(o2=='B'){
				k=1;
				ace==1;
			}
		}
		if(o1=='D'){
			if(o2=='F'){
				k=1;
				ace=1;
			}
		}
		if(o1=='F'){
			if(o2=='D'){
				k=1;
				ace=1;
			}
		}
	}
	cout<<j<<q<<k<<ace;
	return 0;
}
