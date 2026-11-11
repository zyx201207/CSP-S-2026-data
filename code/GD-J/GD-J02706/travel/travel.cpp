#include <bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000";
	}
	else{
		cout<<1;
		string c=x.substr(0,2),d=y.substr(0,2);
		if(c!=d){
			cout<<"000";
		}
		else{
			cout<<1;
			char e=x[2],f=y[2];
			if((e<='C'&&f<='C')||(e>='D'&&f>='D')){
				cout<<1;
				if((abs((int)(e-f))==1)||(e=='D'&&f=='F')||(e=='F'&&f=='D')){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
