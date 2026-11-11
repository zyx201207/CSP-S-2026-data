#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	int s3=int(s1[0]-'0')*10+int(s1[1]-'0'),s4=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(s3!=s4){
		cout<<"1000";
		return 0;
	}
	if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
		if(s1[2]>'C'&&s2[2]>'C'){
			cout<<"1111";
			return 0;
		}
		if(abs(s1[2]-s2[2])==1){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
		}
	}
	else{
		cout<<"1100";
		return 0;
	}
	return 0;
} 
