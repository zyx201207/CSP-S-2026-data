#include<bits/stdc++.h>
using namespace std;
struct zw{
	string cx,zwh;
};
zw a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.cx>>a.zwh>>b.cx>>b.zwh;
	if(a.cx==b.cx){
		cout<<1;
		if(a.zwh[0]==b.zwh[0]&&a.zwh[1]==b.zwh[1]){
			cout<<1;
			if(((a.zwh[2]>='A'&&a.zwh[2]<='C')&&(b.zwh[2]>='A'&&b.zwh[2]<='C'))||((a.zwh[2]>='D'&&a.zwh[2]<='F')&&(b.zwh[2]>='D'&&b.zwh[2]<='F'))){
				cout<<1;
				if((a.zwh[2]>='A'&&a.zwh[2]<='C')&&(b.zwh[2]>='A'&&b.zwh[2]<='C')){
					if(a.zwh[2]>b.zwh[2]){
						if(b.zwh[2]+1==a.zwh[2]){
							cout<<1;
						}else cout<<0;
					}else{
						if(b.zwh[2]-1==a.zwh[2]){
							cout<<1;
						}else cout<<0;
					}
				}else if((a.zwh[2]>='D'&&a.zwh[2]<='F')&&(b.zwh[2]>='D'&&b.zwh[2]<='F')){
					cout<<1;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
