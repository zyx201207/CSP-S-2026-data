#include<bits/stdc++.h>
#define ll long long
using namespace std;
string 	a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	string c;
	c=a[0]+a[1];
	string d;
	d=b[0]+b[1];
	if(c!=d){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
		cout<<"1";
		if(a[2]+1==b[2]||b[2]+1==a[2]){
			cout<<'1';
		}else{
			cout<<'0';
		}
		return 0;
	}
	if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
		cout<<"1";
		if(a[2]!=b[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	cout<<"00";
	return 0;
}
