#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string x1,x2,r1,r2;
	
	cin>>r1>>r2>>x1>>x2;
	
	int ma=0;
	
	if(r1 == x1) cout<<1,ma=1;
	else cout<<0;
	
	if(ma && r2[0] == x2[0] && r2[1] == x2[1]) cout<<1,ma=1;
	else cout<<0,ma=0;
	
	
	if(ma && (r2[2] <= 'C' && x2[2] <= 'C') || (r2[2] >= 'D' && x2[2] >= 'D')){
		cout<<1;
		ma = 1;
	}
	else cout<<0,ma = 0;
	
	if(ma && ((r2[2]-1 == x2[2] || r2[2]+1 == x2[2]) || (x2[2] == 'D' && r2[2] == 'F') || (r2[2] == 'D' && x2[2] == 'F'))) cout<<1;
	else cout<<0;
	
	return 0;
}
