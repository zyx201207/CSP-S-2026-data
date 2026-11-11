#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(" travel.in","r",stdin);
	freopen(" travel.in","w",stdout);
	int a,b,c,d;
char n,m;
	cin>>a>>b>>c>>d;
	cin>>n>>m;
	if(a=c){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
	
	
	
	if(b/10==d/10){
		cout<<"1";
	}
	else{
		cout<<"0";
	}


if(b%10==d%10){
	cout<<"1";
}
else{
	cout<<"0";
}

 

	return 0;
} 
