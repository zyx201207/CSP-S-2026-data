#include <bits/stdc++.h>
using namespace std; 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1=" ";
	string s1=" ";
	string c2=" ";
	string s2=" ";
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		cout<<1;
		if (s1[0] == s2[0]){
		    if (s1[1] == s2[1]){
			    cout<<1;
			    if (s1[2]=='D' or s1[2]=='E'){
	            	if (s2[2]=='D' or s2[2]=='E'){
		            	cout<<1;
		            	cout<<1;
		            }
		            else{
			            cout<<0;
			            cout<<0;
		            }
	            }
	            else{
		            if (s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
			            cout<<1;
			            if (s1[2]=='B' or s2[2]=='B'){
				            cout<<1;
			            }
			            else{
				            cout<<0;
			            }
		            }
		            else{
			            cout<<0;
			            cout<<0;
		            }
	            }
		    }
	    	else{
		        cout<<0;
		        cout<<0;
		        cout<<0;
	        }
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;	
}
