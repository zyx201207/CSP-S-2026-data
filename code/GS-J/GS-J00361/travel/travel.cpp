#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s1,s2;
	bool f,x,y;
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(a==b){
		f=true;
		cout<<1;
	}else{
		f=false;
		cout<<0;
	}
	if(f&&s1[1]==s2[1]){
		x=true;
		cout<<1;
	}else{
		x=false;
		cout<<0;
	}
	int n=abs(char(s1[2])-char(s2[2]));
	if(f&&n<=2&&x){
		y=true;
		cout<<1;
	}else{
		y=false;
		cout<<0;
	}
	if(f&&abs(char(s1[2])-char(s2[2]))==1&&x&&y){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
