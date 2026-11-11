#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	//cout<<endl;
	//cout<<endl<<s1[0]<<endl;
	int a=(s1[0]-'0')*10+(s1[1]-'0');
	//cout<<endl<<a<<endl;
	int b=(s2[0]-'0')*10+(s2[1]-'0');
	//cout<<endl<<b<<endl;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char x=s1[2],y=s2[2];
	if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
		cout<<1;
		if((x>='D'&&y>='D')){
			cout<<1;
		}
		else if(x<='C'&&y<='C'){
			if((x=='A'&&y=='C')||(x=='C'&&y=='A')){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
	else{
		cout<<0<<0;
	}
	
	return 0;
}
