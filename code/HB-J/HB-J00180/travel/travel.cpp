#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx1,cx2,p1,p2;char zw1,zw2;
	scanf("%lld %lld%c %lld %lld%c",&cx1,&p1,&zw1,&cx2,&p2,&zw2);
	int z1=zw1-'A'+1,z2=zw2-'A'+1;
	if(cx1!=cx2) {
		cout<<"0000";
		return 0;
	}
	if(p1!=p2) {
		cout<<"1000";
		return 0;
	}
	if(z1>z2) swap(z1,z2);
	if(1<=z1 and z1<=3 and 4<=z2 and z2<=5) {
		cout<<"1100";
		return 0;
	}
	if(z2-z1!=1) {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
