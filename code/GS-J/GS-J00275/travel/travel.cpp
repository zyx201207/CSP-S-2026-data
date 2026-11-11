#include<bits/stdc++.h>
using namespace std;
string A,B,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>a>>B>>b;
	if(A==B){
		cout<<1;
		if(a[1]+a[0]*10==b[1]+b[0]*10){
			cout<<1;
			if(a[2]=='A'&&b[2]=='B')	cout<<1<<1;
			if(a[2]=='B'&&b[2]=='C')	cout<<1<<1;
			if(a[2]=='D'&&b[2]=='F')	cout<<1<<1;
			if(a[2]=='B'&&b[2]=='A')	cout<<1<<1;
			if(a[2]=='C'&&b[2]=='B')	cout<<1<<1;
			if(a[2]=='F'&&b[2]=='D')	cout<<1<<1;
			
			if(a[2]=='A'&&b[2]=='C')	cout<<1<<0;
			if(a[2]=='C'&&b[2]=='A')	cout<<1<<0;
			if(a[2]=='D'&&b[2]=='C')	cout<<0<<0;
			if(a[2]=='C'&&b[2]=='D')	cout<<0<<0;
			return 0;
		}
	}	
		
	cout<<0<<0<<0;
	return 0;
}
