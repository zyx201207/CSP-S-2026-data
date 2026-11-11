#include<bits/stdc++.h>
using namespace std;
int c1,c2,flag=1;
string s1,s2;
bool ce(){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			return 1;
		}
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			return 1;
		}
	}
	return 0;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		flag=0;
	}
	cout<<flag;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		flag=0;
	}
	cout<<flag;
	if(ce()==0){
		flag=0;
	}
	cout<<flag;
	if(ce()==1){
		if(s1[2]-s2[2]!=1&&s1[2]-s2[2]!=-1){
			flag=0;
		}
	}else{
		flag=0;
	}
	cout<<flag;
	return 0;
}
