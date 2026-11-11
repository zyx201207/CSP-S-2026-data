#include<bits/stdc++.h>
using namespace std;
int a,c,x=0,y=0,aa=0;
string b[100],d[100];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	if(a==c){
			cout<<"1";
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	for(int i=1;i<=2;i++){
		if(b[i]==d[i]){
			x=1;
		}else{
			x=0;
		}
	}
	for(int i=2;i<=3;i++){
		if(b[i]="D"&&d[i]="E"){
			y=1;
		}
		if(b[i]="E"&&d[i]="D"){
			y=1;
		}
		if(b[i]="A"&&d[i]="B"){
			y=1;
		}
		if(b[i]="A"&&d[i]="C"){
			y=1;
		}
		if(b[i]="B"&&d[i]="C"){
			y=1;
		}else{
			y=0;
		}
	}
	for(int i=2;i<=3;i++){
		if(b[i]+1==d[i]||b[i]-1==d[i]){
			aa=1;
		}else{
			aa=0;
		}
	}
	cout<<x<<y<<aa;

		
	
	
	return 0;
}
