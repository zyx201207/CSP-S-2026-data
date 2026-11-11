#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if (c1[i]!=c2[i]){
			a=0;
		}
	}
	if (a==0){
		cout<<"0000";
		return 0;;
	}else{
		cout<<"1";
	}
	for(int i=0;i<2;i++){
		if (s1[i]!=s2[i]){
			a=0;
		}
	}
	if (a==0){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if(s1[2]-97>=3&&s2[2]-97>=3){
		a=1;
	}else if(s1[2]-65<=2&&s2[2]-65<=2){
		a=1;
	}else{
		a=0;
	}
	if (a==0){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
	cout<<1;
	else
	cout<<0;
	
	
	
	return 0;
} 
