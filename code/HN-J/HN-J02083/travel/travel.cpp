#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	//2
	if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2){
		cout<<"1";	
	}else{
		cout<<"0";
	}
	//3
	if(s1[0]==s2[0] && s1[1]==s2[1] &&c1==c2){
		if(s1[2]>='D'){
			if(s2[2]>='D'){
				cout<<"1";
			}else{ 
			 cout<<"0";
			}
		}
		if(s1[2]<='c'){
			if(s2[2]<='C'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"0";
	}
	//4
	if(s1[2]=='D' && s2[2]=='C'){
		cout<<"0";
		return 0;
	}
	if(s2[2]=='D' && s1[2]=='C'){
		cout<<"0";
		return 0;
	}
	if(c1!=c2){
		cout<<"0";
		return 0;
	}
	if(s1[1]-s2[1]<=0 && s1[2]-s2[2]<=1 && s1[2]!=s2[2]){
		cout<<"1";
		return 0; 
	}else if(s1[1]-s2[1]<=0 && s1[2]-s2[2]<=1 && s1[2]==s2[2]){
		cout<<"1";
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//02 01A 02 01B
//02 01C 02 01A
//02 01C 02 01D
//02 02B 02 01A
//02 01A 03 01A
