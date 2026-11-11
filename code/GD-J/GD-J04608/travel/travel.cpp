#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string c1,s1,s2,c2;
	int ans1=0,ans2=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		
		for(int i=0;i<s1.size();i++){
		char c=s1[i];
		if(c>='0'&&c<='9'){
		   ans1=c;	
		}
	}
	for(int i=0;i<s2.size();i++){
		char d=s2[i];
		if(d>='0'&&d<='9'){
		   ans2=d;	
		}
	}
	if(ans1==ans2){
		cout<<"1";
		
		char e=s1[s1.size()-1];
		char f=s2[s2.size()-1];
	if(e>='A'&&e<='C'&&f>='A'&&f<='C'){
		cout<<"1";
		 if(e=='D'||e=='C'&&f=='D'||f=='C'){
		        cout<<"0";
        	}else if(e=='D'||e=='F'&&f=='D'||f=='F'){
	        	cout<<"1";

	       }else	if(e+1==f||f+1==e){
		           cout<<"1";
          	}else cout<<"0";
		   
	}else{
		if(e>='D'&&e<='F'&&f>='D'&&f<='F'){
		   cout<<"1";
		   if(e=='D'||e=='C'&&f=='D'||f=='C'){
		        cout<<"0";
        	}else if(e=='D'||e=='F'&&f=='D'||f=='F'){
	        	cout<<"1";

	       }else	if(e+1==f||f+1==e){
		           cout<<"1";
          	}else cout<<"0";
		   
             	}
	     	    else cout<<"00";
        	}
     	}else cout<<"000";
	
	}else cout<<"0000";
	
	return 0;
} 

