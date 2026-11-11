#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	bool n=0;
	string s1,s2;
	scanf("%0d",&a);
	cin>>s1;
	scanf("%0d",&b);
	cin>>s2;
	if(a==b){
		cout<<1;
		n=1;
	} 
	else {
		cout<<0;
		n=0; 
	}
	int x,y;
	x=(s1[0]-48)*10+(s1[1]-48);
	y=(s2[0]-48)*10+(s2[1]-48);
	if(x==y&&n==1) {
		cout<<1;
		n=1;
	}
	else{
		cout<<0;
		n=0;
	} 
	int ans=s1[2]+s2[2];
	if((ans==131||ans==132||ans==133||ans==139)&&n==1){
		cout<<1;
		n=1;
	} 
	else {
		cout<<0;
		n=0;
	}
	if((ans==131||ans==133||ans==139)&&n==1){
		cout<<1;
	} 
	else cout<<0;
	return 0;
} 
