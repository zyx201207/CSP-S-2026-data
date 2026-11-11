#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string a1;
	string b;
	string b1;
	int sum=0;
	cin>>a>>a1>>b>>b1;
		if(a==b){
			sum=1;
		}
		else{
			sum=0;
		}
	if(sum==1){
		cout<<"1";
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(a1[i]==b1[i]){
			sum=1;
		}
		else{
			sum=0;
		}
	}
	if(sum==1){
		cout<<"1";
	}
	else{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'&&b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
		cout<<'1';
	}
	else if(a1[2]=='D'||a1[2]=='F'&&b1[2]=='D'||b1[2]=='F'){
		cout<<'1';
	}
	else{
		cout<<"0";
	}
	if(a1[2]=='D'||a1[2]=='F'){
		cout<<'1';
	}
	else if(a1[2]=='B'||b1[2]=='B'){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
