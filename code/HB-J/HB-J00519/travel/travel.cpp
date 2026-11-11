#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ten year oi one groud null no open long long meet grandfather
ll zh(string s){
	ll cnt=0;
	for(int i=0;i<2;i++){
		cnt*=10;
		cnt+=s[i]-'0';
	}
	return cnt;
}
string xfi,xsc;
string yfi,ysc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);//02 01A 02 01B
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xfi>>xsc;
	cin>>yfi>>ysc;
	if(zh(xfi)!=zh(yfi)){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(zh(xsc)!=zh(ysc)){cout<<"000";return 0;}
	else cout<<1;
	bool xxx=0,yyy=0;
	if(ysc[2]=='A'||ysc[2]=='B'||ysc[2]=='C'){
		yyy=1;
	}
	if(xsc[2]=='A'||xsc[2]=='B'||xsc[2]=='C'){
		xxx=1;
	}
	if(xxx==yyy)cout<<1;
	else {cout<<"00";return 0;}
	if(abs((int)ysc[2]-(int)xsc[2])==1)cout<<"1";
	else cout<<"0";
	return 0;
}
