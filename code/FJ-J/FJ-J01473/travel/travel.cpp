#include<bits/stdc++.h>
using namespace std;
string x,y,u,v;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>u>>v;
	string p=y.substr(0,2),q=v.substr(0,2);
	char w=y[2],h=v[2];
	if(x==u){
		a=1;
		if(p==q){
			b=1;
			if((w<='C'&&h<='C')||(w>='D'&&h>='D')){
				c=1;
				if((w+1==h||w-1==h)&&(!((w=='C'&&h=='D')||(w=='D'&&h=='C')))){
					d=1;
				}
			}
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
