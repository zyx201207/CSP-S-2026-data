#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int cr,cx,sr1,sx1;
	char sr2,sx2;
	cin>>cr>>sr1>>sr2;
	cin>>cx>>sx1>>sx2;
	
	if(cr==cx){
		cout<<1;
		if(sr1==sx1){
			cout<<1;
			if( ( (sr2>='A'&&sr2<='C')
				&&(sx2>='A'&&sx2<='C') )||
				( (sr2>='D'&&sr2<='F')
				&&(sx2>='D'&&sx2<='F') )
				){
				cout<<1;
				if(abs(sr2-sx2)<=1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}

