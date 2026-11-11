#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	for(int i=1;i<=17;i++){
		cin>>a>>c;
		if(a==1||16 ||c==1||16){
			return 0;
		}
	}
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	for(int j=1;j<=5;j++){
		cin>>b>>d;
	}
	if(b==d){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(b==d&&b==1&&d==2||b==2&&d==1||b==2&&d==3||b==3&&d==2||b==4&&d==5||b==5&&d==4){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(b==1&&d==2||b==2&&d==1||b==2&&d==3||b==3&&d==2||b==4&&d==5||b==5&&d==4){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
