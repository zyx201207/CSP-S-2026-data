#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdout);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans=1,sum=1;
	//是否在一个车厢 
	if(c1==c2){
		cout<<1;
	}
	else{
		ans=0;
		cout<<0;
	}
	//是否在一排 
	if(ans==0){
		cout<<0;
		ans=0;
	}
	else{
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
		}
	}
	
	if(ans==0){
		cout<<0;
	}
	if(s1[2]>s2[2]+2){
		cout<<0;
	}
	else if(s1[2]<s2[2]-2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	
	if(s1[2]==s2[2]-2){
		cout<<1;
	}
	else if(s1[2]==s2[2]+2){
		cout<<0;
		
	}
	else if(s1[2]==s2[2]+1){
		cout<<1;
		
	}
	else if(s1[2]==s2[2]-1){
		cout<<1;
		
	}
	else cout<<0;
	return 0;
} 
