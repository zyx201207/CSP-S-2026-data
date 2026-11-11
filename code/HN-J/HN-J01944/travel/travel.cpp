#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travelin","r","stdin");
	freopen("tranelout","w","stdout");
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
	 	cout<<"0000";
	 }
	 else{
		cout<<"1";
		if(s1[1]==s2[1]){
			cout<<"1";
		}
		else{
			cout<<"0";
			}
		if(s1[1]>=1||s1[1]<5||s2[1]>=1||s2[1]<5&&s1[1]==4||s2[1]==5&&s1[1]==5||s2[1]==5){
				cout<<"1";	
			}
			else{
				cout<<"0";
		}

		if(s1[2]>s2[2]||s1[2]-1==s2[2]&&s1[2]<s2[2]||s1[2]==s2[2]-1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
