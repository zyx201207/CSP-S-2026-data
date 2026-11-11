#include<bits/stdc++.h>
using namespace std;
#define int long long
string c,c2,x,x2,c3,x3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>c2>>x>>x2;
	if(c==x){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	c3=c2[0]+c2[1];
	x3=x2[0]+x2[1];
	if(c3==x3){
		cout<<1;
		if(c2[2]>='A'&&c2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'){
			cout<<1;
			if(c2[2]-x2[2]==1||x2[2]-c2[2]==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(c2[2]>='D'&&c2[2]<='F'&&x2[2]>='D'&&x2[2]<='F'){
				cout<<1;
				if(c2[2]-x2[2]==1||x2[2]-c2[2]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}
	}else{
		cout<<0<<0<<0;
	}
	return 0;
} 
