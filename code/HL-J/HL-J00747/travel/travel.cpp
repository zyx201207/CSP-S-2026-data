#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		if(s1==s2){
			cout<<"1110";
			return 0;
		}
		
	}
	if(c1==c2){
		cout<<"1";
		string s3=s1;
		string s4=s2;
		s3.pop_back();
		s4.pop_back();
		if(s3==s4){
			cout<<"100";
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}  