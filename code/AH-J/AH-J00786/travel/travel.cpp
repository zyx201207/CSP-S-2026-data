#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int x=0,m=0;
	string n1,n2;
	string a,b;
	for(int i=0;i<2;i++){
		cin>>n1[i];
	}
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	for(int i=0;i<2;i++){
		cin>>n2[i];
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	for(int i=0;i<2;i++){
		if(n1[i]==n2[i]){
			x++;
		}
	}
	if(x==2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(a[i]==b[i]){
			m++;
		}
	}
	if(m==2){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a[2]=='A'){
		if(b[2] =='B' or b[2] =='C'){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a[2]=='B'){
		if(b[2] =='A' or b[2] =='C'){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a[2]=='C'){
		if(b[2] =='B' or b[2] =='C'){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a[2]=='D'){
		if(b[2] =='F'){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a[2]=='F'){
		if(b[2] =='D'){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a[2]=='A'){
		if(b[2] =='B'){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
		return 0;
		}
	}
	if(a[2]=='B'){
		if(b[2] =='A' or b[2] =='C'){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
	}
	if(a[2]=='C'){
		if(b[2] =='B'){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
	}
	if(a[2]=='D'){
		if(b[2] =='E'){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
	}
	if(a[2]=='E'){
		if(b[2] =='D'){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
	}
	return 0;
}
