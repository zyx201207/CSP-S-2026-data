#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string R,X;
	cin>>r>>R>>x>>X;
	
	if(r!=x){
		cout<<"0000";
		return 0;
	}
	if(R[0]!=X[0]){
		cout<<1000;
		return 0;
	}
	if(R[1]!=X[1]){
		cout<<1000;
		return 0;
	}
	if((R[2]=='D') && (X[2]=='C') || (R[2]=='C') && (X[2]=='D')){
		cout<<1100;
		return 0;
	}
	if((R[2]=='A' && X[2]=='C') || (R[2]=='C' && X[2]=='A')){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}
