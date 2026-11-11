#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c[3],d[3];
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c[0]+c[1]==d[0]+d[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(int(c[2])-65<3 && int(d[2])-65<3){
		cout<<1;
	}
	else if(int(c[2])-65>=3 && int(d[2])-65>=3){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(int(c[2])-int(d[2])==1 || int(c[2])-int(d[2])==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
