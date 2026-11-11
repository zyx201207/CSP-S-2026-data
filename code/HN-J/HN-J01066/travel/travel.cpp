#include<bits/stdc++.h>
using namespace std;
int main(){
	freoprn("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	int a[10];
	char a1[10];
	cin>>a[0];
	cin>>a[1];
	cin>>a1[0];
	cin>>a[2];
	cin>>a[3];
	cin>>a1[1];
	if(a[0]==a[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	if(a[1]==a[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	if(a1[0]>=65||a1[0]<=67&&a1[1]>=65||a1[1]<=67||a1[0]==68||a1[0]==69&&a1[1]==68||a1[1]==69){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	if(a1[0]-a1[1]==1||a1[0]-a1[1]==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
