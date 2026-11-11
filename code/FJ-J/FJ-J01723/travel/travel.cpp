#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,aa,bb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>aa>>bb;
	if(a==aa){
		cout<<1;
		if(b[0]==bb[0]&&b[1]==bb[1]){
			cout<<1;
			int x=abs(b[2]-bb[2]);
			if(b[2]>='A'&&b[2]<='C'&&bb[2]>='A'&&bb[2]<='C'){
				cout<<1;
				if(x==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(b[2]>='D'&&b[2]<='F'&&bb[2]>='D'&&bb[2]<='F'){
				cout<<1;
				if(x==1){
					cout<<1;
				}else{
					cout<<0;
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
