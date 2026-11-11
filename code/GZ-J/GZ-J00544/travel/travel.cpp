//GZ-J00544，秦语涵，贵阳云岩区中天中学 
#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
string a;  
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	if(a[0]==a[5]&&a[1]==a[6]){
		cout<<"1";
		if(a[2]==a[7] && a[3]==a[8]){
			cout<<"1";
			if(a[4]>='A'&&a[4]<='C'&&a[9]>='A'&&a[9]<='C'||a[4]>='D'&&a[4]<='F'&&a[9]>='D'&&a[9]<='F'){
				cout<<"1";
				if(a[4]=='A'&&a[9]=='B'||a[4]=='B'&&a[9]=='C'||a[4]=='D'&&a[9]=='F')cout<<"1";
				else cout<<"0";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}
