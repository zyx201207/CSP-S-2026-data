#include<bits/stdc++.h>
using namespace std;
string b,c,d;
char e,h;
int m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	if(s1==s3){
		b+="1";
	}else{
		b+="0";
	}
    for(int i=0;i<s2.size();i++){
    	if(s2[i]>='0'&&s2[i]<='9') c+=s2[i];
    		if(s4[i]>='0'&&s2[i]<='9') d+=s4[i];
		if(s2[i]>='A'&&s2[i]<='Z'){
			e+=s2[i];
			m+=s2[i];
		} 
		if(s4[i]>='A'&&s4[i]<='Z'){
			h+=s4[i];
			n+=s4[i];	
		} 
	}
	if(c==d){
			b+="1";
		}else{
			b+="0";
		}
	if(e>='A'&&e<='C'&&h>='A'&&h<='C') {
			b+="1";
		}else{
			b+="0";	
		}
	if(e==h&&m+n==135&&n+1!=m||m+1!=n||m==67&&n==68||m==68&&n==67){
	   b+="0";			
		}else{
		b+="1";	
	}
cout<<b;
	return 0;
}
 
