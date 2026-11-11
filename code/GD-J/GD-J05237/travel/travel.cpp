#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int l1=s1.size()-1,l2=s2.size()-1;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	else{
		string a,b;
		a="";b="";
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				a+=s1[i];
			}
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				b+=s2[i];
			}
		}
		if(a!=b){
			cout<<"1000"<<endl;
			return 0;
		}
		char c,d;
		c=s1[l1];d=s2[l2];
		if((c<='C'&&d<='C')||(c>='D'&&d>='D')){
			if(abs(c-d)==1){
				cout<<"1111"<<endl;
				return 0;
			}
			else{
				cout<<"1110"<<endl;
			}
		}
		else{
			cout<<"1100"<<endl;
			return 0;
		}
		}
	return 0;
} 
