#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	int p1,p2;
	p1 = (s1[0]-'0')*10+(s1[1]-'0');
	p2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2&&a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	
	int l1 = s1[2]>='E'?s1[2]-'A':s1[2]-'A'+1;
	int l2 = s2[2]>='E'?s2[2]-'A':s2[2]-'A'+1;
	if(p1==p2&&a==b&&((l1<=3&&l2<=3)||(l1>=4&&l2>=4))){
		cout<<1;
	}else{
		cout<<0;
	}
	
	bool g = (l1==3||l2==3) && (l1==4||l2==4);
	if(abs(l1-l2)==1&&p1==p2&&a==b&&!g){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
