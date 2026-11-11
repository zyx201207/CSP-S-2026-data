#include<bits/stdc++.h>
using namespace std;
int a,b,h,t;
string c,d;
char l,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b) return cout<<"0000",0;
	cout<<1;
	for(auto i:c){
		if(isdigit(i)) h*=10,h+=i-'0';
		else l=i;
	}
	for(auto i:d){
		if(isdigit(i)) t*=10,t+=i-'0';
		else k=i;
	}
	if(t!=h) return cout<<"000",0;
	cout<<1;
	if((l<='C'&&k<='C')||(l>='D'&&k>='D')) cout<<1;
	else return cout<<"00",0;
	if((l+1==k)||(k+1==l)) cout<<1;
	else cout<<"0";
} 
