#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,a1,a2;
	cin>>x1>>a1>>x2>>a2;
	if(x1==x2){
		cout<<1;
		if(a1==a2){
			cout<<1;}
		else{
			cout<<1<<0<<0<<0;
			return 0;}
			}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
	}
