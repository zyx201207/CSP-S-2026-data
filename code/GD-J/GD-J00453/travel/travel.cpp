#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int cx,cy;
string zx,zy;
int main(){
	fastio;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>zx>>cy>>zy;
	string xxxx=zx.substr(0,2);
	char xxxx1=zx[2];
	string yyyy=zy.substr(0,2);
	char yyyy1=zy[2];
	if(cx != cy){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(xxxx!=yyyy){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((xxxx1<='C' && yyyy1<='C') || (xxxx1>='D' && yyyy1>='D')){
		cout<<1;
		if(abs((int)xxxx1-(int)yyyy1)<=1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
