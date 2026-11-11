#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	char b1[10]={},b2[10]={};
	cin>>a1>>b1;
	cin>>a2>>b2;
	if(a1==a2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]&&(((b1[2]+1==b2[2]||b1[2]-1==b2[2])&&b1[2]!='C'&&b1[2]!='D')||(b1[2]=='C'&&b1[2]-2==b2[2])||(b1[2]=='A'&&b1[2]+2==b2[2]))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]&&(b1[2]+1==b2[2]||b1[2]-1==b2[2])&&b1[2]!='C'&&b1[2]!='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
