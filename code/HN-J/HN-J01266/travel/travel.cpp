#include<bits/stdc++.h>
using namespace std;
string xcx;
string rcx;
char xrz[4];
char xxz[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xcx>>xxz>>rcx>>xrz;
	if(xcx==rcx){
		cout<<1;
		if(xxz[0]==xrz[0]&&xxz[1]==xrz[1]){
			cout<<1;
			if(xxz[2]!='D'&&xrz[2]!='D'&&xxz[2]!='E'&&xrz[2]!='E'){
				cout<<1;
				if(xxz[2]==xrz[2]+1||xxz[2]==xrz[2]-1){
			    	cout<<1;
			    	return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
			if(xxz[2]!='A'&&xrz[2]!='A'&&xxz[2]!='B'&&xrz[2]!='B'&&xxz[2]!='C'&&xrz[2]!='C'){
				cout<<1;
			    if(xxz[2]==xrz[2]+1||xxz[2]==xrz[2]-1){
			    	cout<<1;
			    	return 0;
				}else{
					cout<<0;
					return 0;
				}
			    	
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
} 
