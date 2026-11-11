#include<bits/stdc++.h>
using namespace std;
char a[8],b[8];
bool x,y,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<6;i++){
		cin>>a[i];
	}
	for(int i=1;i<6;i++){
		cin>>b[i];
	}
	
	if(a[5]=='A'||a[5]=='B'||a[5]=='C'){
		x=1;
	}else{
		x=0;
	}
	if(b[5]=='A'||b[5]=='B'||b[5]=='C'){
		y=1;
	}else{
		y=0;
	}
	
	if(a[5]=='A'&&b[5]=='C'){
		c=0;
	}else if(a[5]=='C'&&b[5]=='A'){
		c=0;
	}else{
		c=1;
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<"1";
		if(a[3]==b[3]&&a[4]==b[4]){
			cout<<"1";
			if(x==y){
				cout<<"1"<<c;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
