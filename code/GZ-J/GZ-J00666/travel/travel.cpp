//姓名：朱栩熠  准考证号：GZ-J00666 学校：贵阳第十八中学 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>c2;
	string s1,s2;
	
	cin>>s1>>s2;
	
	if(c1=s1[0]){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	if(c1=c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[0]=s2[0]){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
		
		if(s2[1]=c2){
			cout<<1;
	 }
		else if(s2[0]=c2){
			cout<<0;
		}
		
		
		return 0;
	}
	
	

