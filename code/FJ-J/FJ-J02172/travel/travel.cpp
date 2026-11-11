#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;
bool pk1(){
	if(rb[2]>='D' and xb[2]>='D')return 1;
	if(rb[2]<='C' and xb[2]<='C')return 1;
	return 0;
}
bool pk2(){
	if(rb[2]=='A' and xb[2]=='B')return 1;
	if(rb[2]=='B' and xb[2]=='A')return 1;
	if(rb[2]=='B' and xb[2]=='C')return 1;
	if(rb[2]=='C' and xb[2]=='B')return 1;
	if(rb[2]=='F' and xb[2]=='D')return 1;
	if(rb[2]=='D' and xb[2]=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>ra>>rb>>xa>>xb;
	
	if(ra==xa){
		cout<<1;
		if(rb[0]==xb[0] and rb[1]==xb[1]){
			cout<<1;
			if(pk1()){
				cout<<1;
				if(pk2()){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
