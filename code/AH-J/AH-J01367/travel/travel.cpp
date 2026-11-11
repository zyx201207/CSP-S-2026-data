#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	/*if(c1!=c2){
		cout<<"0";
	}
	else
	cout<<"1";*/
	for(int i=0;i<c1.size();i++){
		for(int i=0;i<c1.size();i++){
		    if(c1[i]>='1'&&c1[i]<='9'&&c2[i]>='1'&&c2[i]<='9'){
		    	if(c1[i]==c2[i]){
		    		cout<<"1";
				}
				else
				cout<<"0";
			}
	    }
	}
    for(int i=0;i<s1.size();i++){
		for(int i=0;i<s2.size();i++){
		    if(s1[i]>='1'&&s1[i]<='9'&&s2[i]>='1'&&s2[i]<='9'){
		    	if(s1[i]==s2[i]){
		    		cout<<"1";
				}
				else
				cout<<"0";
			}
	    }
	}
	for(int i=0;i<s1.size();i++){
		for(int i=0;i<s2.size();i++){
		    if(s1[i]>='A'&&s1[i]<='F'&&s2[i]>='A'&&s2[i]<='F'){
		    	s1[i]=(s1[i]-'A')%26;
		    	s2[i]=(s2[i]-'A')%26;
		    	if(abs(s1[i]-s2[i]==1&&(s1[i]!=2&&s2[i]!=3))){
		    		cout<<"1";
				}
				else 
				cout<<"0";
			}
	    }
	}
	for(int i=0;i<s1.size();i++){
		for(int i=0;i<s2.size();i++){
		    if(s1[i]>='A'&&s1[i]<='F'&&s2[i]>='A'&&s2[i]<='F'){
		    	if(((s1[i]=='C'&&s2[i]=='D')||(s1[i]=='D'&&s2[i]=='C'))||((s1[i]<='C'&&s2[i]>'C'))||(s1[i]>'C'&&s2[i]<='C')){
		    		cout<<"0";
				}
				else{
				cout<<"1";
				}
			}
		}
	}
	return 0;
} 
