#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<s1<<" "<<s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		cout<<"1100";
		
	}
	
	return 0;
} 
