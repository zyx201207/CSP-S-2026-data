#include <bits/stdc++.h>
using namespace std;
long long cx,cr;
string sx,sr;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr;
	cin>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<"1";
			if((sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')||(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')){
				cout<<"1";
				long long tmpx=sr[2]-'A';
				long long tmpr=sx[2]-'A';
				if(abs(tmpx-tmpr)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
