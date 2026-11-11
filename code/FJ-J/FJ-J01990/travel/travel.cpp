#include<bits/stdc++.h>
using namespace std;
string ac,bc,a,b;
bool pa,pb,pc;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ac>>a>>bc>>b;
	
	if(ac==bc){
		pa=1;
		cout<<1;
	}
	else{
		pa=0;
		cout<<0;
	}
	
	string ap=a.substr(0,2),bp=b.substr(0,2);
	if(ap==bp&&pa){
		pb=1;
		cout<<1;
	}
	else{
		pb=0;
		cout<<0;
	}
	
	char ah=a[2],bh=b[2];
	if(ah<='C'&&ah>='A')
		if(bh<='C'&&bh>='A'&&pb){
			pc=1;
			cout<<1;
		}
		else{
			pc=0;
			cout<<0;
		}	
	else
		if(bh<='F'&&bh>='D'&&pb){
			pc=1;
			cout<<1;
		}
		else{
			pc=0;
			cout<<0;
		}
			
	if((ah-bh==1||ah-bh==-1)&&pc)
		cout<<1;
	else
		cout<<0;
	
	cout<<'\n';
	return 0;
}
