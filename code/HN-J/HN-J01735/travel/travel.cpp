#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
	}
	else if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c[2]<'E'&&d[2]<'E'||c[2]>='E'&&d[2]>='E'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(c[2]==d[2]+1||c[2]==d[2]-1){
		cout<<1;	
	}
	else{
		cout<<0;
	}
	return 0;
} 
