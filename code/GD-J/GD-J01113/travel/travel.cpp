#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=c1[0]*10+c1[1];
	int b1=c2[0]*10+c2[1];
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}
	int a2=s1[0]*10+s1[1];
	int b2=s2[0]*10+s2[1];
	if(a2!=b2){
		cout<<"1000";
		return 0;
	}	
	if(s1[2]=='D'||s1[2]=='F'){
		p=1;
	}
	if(s2[2]=='D'||s2[2]=='F'){
		q=1;
	}	
	if(p!=q){
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='C'){
		if(s2[2]!='B'){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
} 
