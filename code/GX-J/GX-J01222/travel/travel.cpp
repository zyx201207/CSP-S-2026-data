#include <cstdio>
#include <bits/stdc++.h>
	
using namespace std;

bool abc(int a,int b){
	if( (a-b)==1 ||(a-b)==-1 )
	return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string p,q,a,b;
	cin>>p>>a>>q>>b;
	if(p==q){
		cout<<1;
		if((a[0])*10+a[1]==(b[0])*10+b[1]){
			cout<<1;
			if(a[2]<='C' && a[2]>='A'){
				if(b[2]<='C' && b[2]>='A'){
					cout<<1;
					if( abc(a[2],b[2]) ){
						cout<<1;
					}
					else cout<<0;
				}
				else cout<<"00";
			}else
			if(b[2]<='F' && b[2]>='D'){
				cout<<11;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
