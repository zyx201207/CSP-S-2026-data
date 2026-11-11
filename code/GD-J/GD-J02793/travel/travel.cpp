#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	 string c1,s1,c2,s2;
	 cin>>c1>>s1>>c2>>s2;
	 bool a=0,b=0,c=0;
	 if(c1==c2){
	 	c=1;
	 cout<<1;}
	 else{
	 	cout<<0;
	 };
	 if(s1[0]==s2[0] && s1[1]==s2[1] && c==1){
	 	a=1;
	 	cout<<1;
	 }
	 else{
	 	cout<<0;
	 };
	if(a==1 && s1[2]>67 && s2[2]>67){
		cout<<1;
		b=1;
	}
	else if(a==1 && s1[2]<68 && s2[2]<68){
		cout<<1;
		b=1;
	}
	else{
		cout<<0;
	};
	if(b==1&&s1[2]-s2[2]==1||s2[2]-s1[2]==1)cout<<1;
	else{
		cout<<0;
	} 
	
	
	
	




	return 0;
} 
