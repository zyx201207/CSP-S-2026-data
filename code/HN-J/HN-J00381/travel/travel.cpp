#include<bits/stdc++.h>
using namespace std;
int a,b,c;
char c1[15],c2[15],s1[15],s2[15];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3];
	cin>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];	
	a=s1[3];
	b=s2[3];
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
			cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
		}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
		}
	if(a>b){
		if(s1[3]=='D'){
			cout<<"00";
			return 0;
		}
		if(s1[3]=='F'){
			if(s2[3]!='D'){
			cout<<"00";
			return 0;		
			} 
		}
		cout<<"1";
		c=a-b;		
	}
	else{
		if(s2[3]=='D'){
			cout<<"00";
			return 0;
		}
		if(s2[3]=='F'){
			if(s1[3]!='D'){
			cout<<"00";
			return 0;		
			} 
		}
		cout<<"1";
		c=b-a;
	}
	
	 if(c==1){
	 	cout<<"1";
	 }
	 else{
	 	cout<<"0";
	 }
	return 0;
}
