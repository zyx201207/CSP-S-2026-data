#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	bool s=false,p=false,c=false;
	
	
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		s=true;
		cout<<1;
	}
	
	
	if(s&&a1[1]==b1[1]){
		p=true;
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	
	
	int x=abs(char(a1[2])-char(b1[2]));
	int y=abs(char(b1[2])-char(a1[2]));
	
	
	if(s&&x<=2&&p){
		if(((a1[2]>='A'&&a1[2]<='C')&&(b1[2]>='A'&&b1[2]<='C'))||((a1[2]>='D'&&a1[2]<='F')&&(b1[2]>='D'&&b1[2]<='F'))){
			c=true;
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0;
		return 0;
	}
	
	
	if(s&&abs(char(a1[2])-char(b1[2]))==1&&p&&c||abs(char(b1[2])-char(a1[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
