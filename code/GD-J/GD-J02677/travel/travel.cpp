#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int x,y;
	string sx,sy;
	cin>>x>>sx>>y>>sy;
	
	if(x==y){
		cout<<'1';
		if(sx[0]==sy[0] && sx[1]==sy[1]){
			cout<<'1';
			if((sx[2]<='C' && sy[2]<='C') || (sx[2]>='D' && sy[2]>='D')){
				cout<<'1';
				if(abs(sx[2]-sy[2])==1 && !(sx[2]=='C' && sy[2]=='D')) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

