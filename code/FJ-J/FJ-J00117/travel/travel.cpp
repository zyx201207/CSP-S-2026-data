#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,m1,n2,m2;
	string m3=m1,m4=m2;
	cin>>n1>>m1>>n2>>m2;
	if(n1==n2){
		cout<<1;	
	}
	else{
			cout<<"0000";
			return 0;
		}
	//int cnt=m1.size(),cnt2=m2.size();
	//char x=m1[cnt-1],y=m2;
	//m1[cnt-1]=0;
	m3[2]=0;
	m4[2]=0;
	if(m3==m4){
		cout<<1;
		char x=m1[2],y=m2[2];
		if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
			cout<<1;
			if(x=='A'&&y=='B'){
				cout<<1;
				return 0;
			}
			
			if(x=='B'&&(y=='C'||y=='A')){
				cout<<1;
				return 0;	
			}
			
			if(x=='C'&&y=='B'){
				cout<<1;
				return 0;	
			}
			cout<<"0";
			return 0;
		}
		if((x=='D'||x=='F')&&(y=='D'||y=='F')){
			cout<<11;
			return 0;	
		}
		cout<<"00";
		return 0;
	}
	else{
			cout<<000;
			return 0;
		}
	return 0;
}