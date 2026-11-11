#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a1,c=0;
	char b1[10],b[10];
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}cin>>a1;
	for(int i=0;i<3;i++){
		cin>>b1[i];
	}if(a==a1){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}if((b[0]-'0')*10+b[1]-'0'==(b1[0]-'0')*10+b1[1]-'0'){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}if(b[2]-'A'<=2 and b1[2]-'A'<=2 or b[2]-'D'>=0 and b1[2]-'D'>=0){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}if(b[2]-b1[2]==1 or b[2]-b1[2]==-1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}


