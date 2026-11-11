#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>c[i]; 
	} 
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>d[i]; 
	} 
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(c[1]==d[1]&&c[2]==d[2]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(c[3]=='A'&&d[3]=='B'||c[3]=='A'&&d[3]=='C'||c[3]=='B'&&d[3]=='C'||c[3]=='B'&&d[3]=='A'||c[3]=='C'&&d[3]=='A'||c[3]=='C'&&d[3]=='B'||c[3]=='E'&&d[3]=='F'||c[3]=='F'&&d[3]=='E'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c[3]=='A'&&d[3]=='B'||c[3]=='B'&&d[3]=='C'||c[3]=='B'&&d[3]=='A'||c[3]=='C'&&d[3]=='B'||c[3]=='E'&&d[3]=='F'||c[3]=='F'&&d[3]=='E'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
