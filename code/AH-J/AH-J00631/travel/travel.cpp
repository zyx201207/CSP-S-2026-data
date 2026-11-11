#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pri(char c){
	if(c=='A' || c=='B' || c=='C') return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll c1,c2,z1,z2;
	char s1,s2;
	scanf("%lld %lld%c %lld %lld%c",&c1,&z1,&s1,&c2,&z2,&s2);
	bool p1=(c1==c2);
	bool p2=p1&&(z1==z2);
	bool p3=p2&&(pri(s1)==pri(s2));
	bool p4= p3&&(abs(ll(s1)-ll(s2))==1);
	cout<<p1<<p2<<p3<<p4<<endl;
	return 0;
}
