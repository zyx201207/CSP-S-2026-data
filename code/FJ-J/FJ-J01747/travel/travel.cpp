#include<bits/stdc++.h>
using namespace std;
int main(){
	int rr,xx;
	string r0,x;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rr>>r0>>xx>>x;
	if(rr==xx){
		if(r0[0]==x[0]&&r0[1]==x[1]){
			if( (x[2]=='C'&&r0[2]=='D') || (r0[2]=='C'&&x[2]=='D') ){
				cout<<"1100";
				return 0;
			}
			if(r0[2]-x[2]==1||x[2]-r0[2]==1) cout<<"1111";
			else cout<<"1110";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
