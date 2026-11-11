#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int x1=0,x2=1,x3=0,x4=0,k1,k2;
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	//cout<<a<<" "<<s1<<" "<<b<<" "<<s2;
	if(a==b)x1=1;
	if(x1==0){
		cout<<0<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			x2=0;
			break;
		}
	}
	if(x2==0){
		cout<<1<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		k1=1;
	}else{
		k1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		k2=1;
	}else{
		k2=2;
	}
	if(k1==k2)x3=1;
	if(x3==0){
		cout<<1<<" "<<1<<" "<<0<<" "<<0;
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')
	||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
		x4=1;
	}
	cout<<1<<" "<<1<<" "<<1<<" "<<x4;
	return 0;
}
