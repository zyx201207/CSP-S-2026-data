#include<bits/stdc++.h>
using namespace std;
char a[3],a1[4],b[3],b1[4];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=2;i++){
		cin>>b[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b1[i];
	}
	if(a[1]==b[1] && a[2]==b[2]){
		cout<<'1';
	}else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	if(a1[1]==b1[1] && a1[2]==b1[2]){
		cout<<'1';
	}else{
		cout<<'1'<<'0'<<'0'<<'0';
		return 0;
	}
	for(int i=1;i<=1;i++){
		if(a1[3]=='A' && b1[3]=='B'){
			cout<<'1';
			break;
		}
		if(a1[3]=='A' && b1[3]=='C'){
			cout<<'1';
			break;
		}
		if(a1[3]=='B' && b1[3]=='C'){
			cout<<'1';
			break;
		}
		if(a1[3]=='B' && b1[3]=='A'){
			cout<<'1';
			break;
		}
		if(a1[3]=='C' && b1[3]=='A'){
			cout<<'1';
			break;
		}
		if(a1[3]=='C' && b1[3]=='B'){
			cout<<'1';
			break;
		}
		if(a1[3]=='D' && b1[3]=='F'){
			cout<<'1'<<'1';
			return 0;
		}
		if(a1[3]=='F' && b1[3]=='D'){
			cout<<'1'<<'1';
			return 0;
		}
		cout<<'0';
	}
	if(a1[3]=='A' && b1[3]=='B'){
		cout<<'1';
		return 0;
	}
	if(a1[3]=='B' && b1[3]=='A'){
		cout<<'1';
		return 0;
	}
	if(a1[3]=='B' && b1[3]=='C'){
		cout<<'1';
		return 0;
	}
	if(a1[3]=='C' && b1[3]=='B'){
		cout<<'1';
		return 0;
	}
	cout<<'0';
	return 0;
} 
