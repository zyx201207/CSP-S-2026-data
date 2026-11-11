#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	bool j=false,k=false,l=false;
	string c,d;
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a==b){
		cout<<"1";
		j=true;
	}
	else{
		cout<<"0";
	}
	if(j==true){
	if(c[0]+0==d[0]+0&&c[1]+0==d[1]+0){
		cout<<"1";
		k=true;
	}
	else{
		cout<<"0";
	}
	}
	if(k==true){
		if(c[2]+0<=67&&d[2]+0<=67||c[2]+0>67&&d[2]+0>67){
		cout<<"1";
		l=true;
	}
	else{
		cout<<"0";
	}
	}
	if(l=true){
		if(c[2]+1==d[2]+0||c[2]+0==d[2]+1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
