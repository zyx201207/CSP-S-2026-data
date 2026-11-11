#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if((r1[0] != x1[0]) || (r1[1] != x1[1])) cout<<"0000";
	else{
		cout<<1;
		if((r2[0] != x2[0]) || (r2[1] != x2[1])) cout<<"000";
		else{
			cout<<1;
			if(!((r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C') && (x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C') && (r2[2] != x2[2])) || ((r2[2] == 'D' || r2[2] == 'F') && (x2[2] == 'D' || x2[2] == 'F') && (r2[2] != x2[2]))) cout<<"00";
			else{
				cout<<1;
				if((r2[2] == 'A' && x2[2] == 'B') || (r2[2] == 'B' && x2[2] == 'A') || (r2[2] == 'C' && x2[2] == 'B') || (r2[2] == 'B' && x2[2] == 'C') || (r2[2] == 'D' && x2[2] == 'F') || (r2[2] == 'F' && x2[2] == 'D')) cout<<1;
				else cout<<0;
			}
		}
	}
	
	return 0;
}
