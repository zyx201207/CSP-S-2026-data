#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ca,cb;
string sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(sa[0]!=sb[0]||sa[1]!=sb[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>'C'&&sb[2]>'C')){
		cout<<1;
		int a=(int)(sa[2]),b=(int)(sb[2]);
		if(abs(a-b)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
