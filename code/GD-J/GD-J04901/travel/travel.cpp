#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int a,b,c,d;
char q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>q>>c>>d>>w;
	int n=q,m=w;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(q<='C'&&w<='C'||q>='D'&&w>='D'){
				cout<<1;
				if(n-m==1||m-n==1||q=='D'&&w=='F'||q=='F'&&w=='D'){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
