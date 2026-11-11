#include<bits/stdc++.h>
using namespace std;
long long i,c1,c2;
string s1,s2;
string k;
bool r=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		k=k+'1';
	}else{
		k=k+'0';
		r=false;
		
	}
	if(r!=false&&s1.size()==s2.size()){
	for(i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				k=k+'0';
				r=false;
			break;	
			}else{
				r=true;
			}
		}	
	}else{
		k=k+'0';
	}
	if(r==true){
		k=k+'1';
	}

	if(r!=false&&(s1[s1.size()-1]-'A'>2&&s2[s2.size()-1]-'A'>2||s1[s1.size()-1]-'A'<=2&&s2[s2.size()-1]-'A'<=2)){
	k=k+'1';	
	}else{
		k=k+'0';
		r=false;
	}
	if(r!=false&&(s2[s2.size()-1]-s1[s1.size()-1]==1||s2[s2.size()-1]-s1[s2.size()-1]==1)){
		k=k+'1';
	}else{
		k=k+'0';
	}
		cout<<k;
		
	return 0;
}
