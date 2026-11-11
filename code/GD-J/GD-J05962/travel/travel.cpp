#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<'1';
		string n1,n2;
		n1=s1[0]+s1[1];
		n2=s2[0]+s2[1];
		
		if(n1==n2){
			cout<<'1';
			s1=s1[2];
			s2=s2[2];
			if(s1[0]<='C'&&s2[0]<='C'||s1[0]>'C'&&s2[0]>'C'){
				cout<<'1';
				int a=s1[0],b=s2[0];
				if(abs(a-b)==1)cout<<'1';
				else{cout<<"0";}
				
			}else{cout<<"00";}
			
		}else{cout<<"000";}
		
	}else{cout<<"0000";}
	
	return 0;
} 
