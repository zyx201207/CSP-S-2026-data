#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 1e6+5;
string rx,rid;
string xx,xid;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>rid>>xx>>xid;
//	cout<<rid[2];
	//if(rid[2]>='A'&&rid[2]<='C')cout<<8<<"\n";
	if(rx==xx){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}
	//cout<<'a';	
	if(rid[1]==xid[1]
	
	&&rx==xx){
			cout<<1;
	}else {
		cout<<"000";
		return 0;
	}
	//cout<<'a';
	
	if(rid[1]==xid[1]&&rx==xx
	
	&&((rid[2]>='A'&&rid[2]<='C'
	&&xid[2]>='A'&&xid[2]<='C')
	||(rid[2]>='D'&&rid[2]<='F'&&xid[2]>='D'
	   &&xid[2]<='F'))){
		    cout<<1;
	}else {
		cout<<"00";
		return 0;
	} 
	//cout<<'a';
	if(rid[1]==xid[1]&&rx==xx
	&&((rid[2]>='A'&&rid[2]<='C'
	&&xid[2]>='A'&&xid[2]<='C')
	||(rid[2]>='D'&&rid[2]<='F'&&xid[2]>='D'
	   &&xid[2]<='F'))&&
	
	rid[2]+1==xid[2]||rid[2]-1==xid[2]){
		    	cout<<1;
	}else cout<<0;
	//cout<<'a';
	return 0;
}

