#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>a1;
	cin>>b1;
	if(a[0]==a1[0]&&a[1]==a1[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==b1[0]&&b[1]==b1[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&b1[2]<='C'&&b[2]>='A'&&b1[2]>='A')||(b[2]<='F'&&b1[2]<='F'&&b[2]>='D'&&b1[2]>='D'&&b1[2]!='E'&&b[2]!='E')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	int e=b[2]-'A'+1;
	int q=b1[2]-'A'+1;
	if((abs(e-q)==1)||(b[2]=='D'&&b1[2]=='F')||(b1[2]=='F'&&b[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	
} 
