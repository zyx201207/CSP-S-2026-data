#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10];
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	int f=0;
	int t=1;
	if(a[0]==a[5]&&a[1]==a[6]){
		cout<<t;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[2]==a[7]&&a[3]==a[8]){
		cout<<t;
	}else{
		cout<<"000";
		return 0;
	}
	if((a[4]<='C'&&a[4]>='A'&&a[9]<='C'&&a[9]>='A')||(a[4]<='F'&&a[4]>='D'&&a[9]<='F'&&a[9]>='D')){
		cout<<t;
	}else{
		cout<<"00";
		return 0;
	}if(((a[4]=='A'&&a[9]=='B')||(a[4]=='B'&&a[9]=='A')||(a[4]=='C'&&a[9]=='B')||(a[4]=='B'&&a[9]=='C'))||((a[4]=='D'&&a[9]=='F')||(a[4]=='F'&&a[9]=='D'))){
		cout<<t;
	}else{
		cout<<f;
	}
	return 0;
}