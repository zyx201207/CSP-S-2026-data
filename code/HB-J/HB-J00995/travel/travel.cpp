#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int a,b,e,f;
char c,d;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	a=(int)s1[0]*10+(int)s1[1];
    b=(int)s2[0]*10+(int)s1[1];
	if(c1==c2&&a==b){
	   cout<<"1";	
	}else{
	   cout<<"0";
	}
	
		c=s1[2],d=s2[2];
		if(c1==c2&&a==b){
			if('A'<=c&&c<='C'&&'A'<=d&&d<='C'){
				cout<<"1";
			}
	        if(c=='D'&&d=='F') cout<<"1";
	        if(c=='F'&&d=='D') cout<<"1";
	        if(c=='C'&&d=='D') cout<<"0";
	        if(c=='D'&&d=='C') cout<<"0";
	}else{
		cout<<"0";
	}
	
	    e=(int)s1[2],f=(int)s2[2];
		if(c1==c2&&a==b){
			if(c=='C'&&d=='D'){
			  cout<<"0";
			}
			if(c=='D'&&d=='C'){
				cout<<"0";
			}
			if(c=='D'&&d=='F') cout<<"1";
	        if(c=='F'&&d=='D') cout<<"1";
			}
		
		if(c1==c2&&a==b){
		if(e==67&&f!=68){
				    if(e-f==1||f-e==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	return 0;
}
