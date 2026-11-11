#include<bits/stdc++.h>
using namespace std;
struct zw{
	string cx,zwh;
}a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a[0].cx>>a[0].zwh>>a[1].cx>>a[1].zwh;
    if(a[0].cx==a[1].cx){
    	cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[0].zwh[0]==a[1].zwh[0] and a[0].zwh[1]==a[1].zwh[1]){
		cout<<"1";
		if((a[0].zwh[2]<='C' and a[1].zwh[2]<='C' and a[0].zwh[2]>='A' and a[1].zwh[2]>='A')or(a[0].zwh[2]<='E' and a[1].zwh[2]<='E' and a[0].zwh[2]>='D' and a[1].zwh[2]>='D')){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	if((a[0].zwh[2]=='A' and a[1].zwh[2]=='B')or(a[0].zwh[2]=='B' and a[1].zwh[2]=='C')or(a[0].zwh[2]=='D' and a[1].zwh[2]=='E')or(a[0].zwh[2]=='B' and a[1].zwh[2]=='A')or(a[0].zwh[2]=='C' and a[1].zwh[2]=='B')or(a[0].zwh[2]=='E' and a[1].zwh[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
