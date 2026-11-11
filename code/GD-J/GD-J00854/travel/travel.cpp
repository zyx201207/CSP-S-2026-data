#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	int a1=0,a2=0;
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			a1=a1*10+s2[i];
		}
	}
	for(int i=0;i<s4.size();i++){
		if(s4[i]>='0'&&s4[i]<='9'){
			a2=a2*10+s4[i];
		}
	}
	if(a1==a2){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	int a=s2[s2.size()-1]-'A',b=s4[s4.size()-1]-'A';
	int c=abs(a-b);
	if(a<=3){
		a=3;
	}else{
		a=5;
	}
	if(b<=2){
		b=3;
	}else{
		b=5;
	}
	if(a==b){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(c==1&&a==b){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
