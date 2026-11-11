#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
    if(c1==c2)
    	cout<<"1";
	else
		cout<<"0";
	string r="";
	string x="";
	r+=s1[0];
	r+=s1[1];
	x+=s2[0];
	x+=s2[1]; 
	if(c1==c2&&x==r)
		cout<<"1";
	else
	    cout<<"0";
	char rr=s1[2];
	char xx=s2[2];
	int xxrr=0;
	if(c1==c2&&x==r){
		if(rr=='D'||rr=='F'){
			if(xx=='D'||rr=='F'){
				cout<<"1";
				xxrr=1;
			}else cout<<"0"; 
		}
		if(rr=='A'||rr=='B'||rr=='C'){
			if(xx=='A'||xx=='B'||xx=='C'){
				cout<<"1";
				xxrr=1;
			}else cout<<"0";
				
		}
	}else cout<<"0";
	if(c1==c2&&x==r&&xxrr==1){
		if(abs((int)rr-(int)xx)==1)
			cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	return 0;
} 
