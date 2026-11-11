#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2){
	 	cout<<1<<" ";
		char l=s1[0]+s1[1];
		char p=s2[0]+s2[1];
		char k=s1[2];
		char n=s2[2];
			if(l==p){
	 		cout<<1<<" ";
				if(k>='A'&&k<='C'&&n>='A'&&n<='C'){
	   			cout<<1<<" ";
	    			if(k=='A'&&n=='B'||k=='B'&&n=='C'||n=='A'&&k=='B'||n=='B'&&k=='C'){
	    	   		cout<<1<<" ";
					}
					else{
			  		cout<<0;
					}
				}
				else if(k=='D'&&n=='F'||n=='D'&&k=='F'){
				cout<<1<<" ";
				cout<<1;	
				}
				else{
				cout<<0<<" ";
				cout<<0;
				}
			}
			else{
				cout<<0<<" ";
				cout<<0<<" ";
				cout<<0;	
			}
		}
		else{
		cout<<0<<" ";
		cout<<0<<" ";
		cout<<0<<" ";
		cout<<0;	
		} 
	return 0;
} 
