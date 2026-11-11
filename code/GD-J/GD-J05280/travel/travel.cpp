#include<bits/stdc++.h>
using namespace std;
string x,y,t;
bool a[15]={1,1,1,0,0,0},f=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>t;
	x+=t;
	cin>>y>>t;
	y+=t;
	if(x[0]+x[1]==y[0]+y[1]){
		cout<<1;
	}
	else{
		cout<<0;
		f=false;
	}
	if(x[2]+x[3]==y[2]+y[3]&&f){
		cout<<1;
	}
	else{
		cout<<0;
		f=false;
	}
	if(x[2]+x[3]==y[2]+y[3]&&a[int(x[4]-'A')]==a[int(y[4]-'A')]&&f){
		cout<<1;
	
	}
	else{
		cout<<0;
		f=false;
	}
	if(f&&abs(x[4]-y[4])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
