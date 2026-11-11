#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1,s2=='A','B','c'){
		cout<<1;
		if(s1==[1]&&s2==[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		
	}
	else if(s1,s2=='D','F'){
		cout<<1;	
		if(s1==[1]&&s2==[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
