#include <bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;char a3,b3;
//freeopen("travel1.in","w",stdin);
//froepen("travel1.out","r",stdout);
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;cin>>a1>>s1>>b1>>s2;
	a2=s1[0]*10+s1[1],b2=s2[0]*10+s2[1],a3=s1[2],b3=s2[2];
	if(a3>b3) swap(a3,b3);
	if(a1!=b1) return cout<<"0000",0;
	if(a2!=b2) return cout<<"1000",0;
	if(!(a3<='C'&&b3<='C'||a3>='D'&&b3>='D')) return cout<<"1100",0;
	if(a3=='A'&&b3=='B'||a3=='B'&&b3=='C'||a3=='D'&&b3=='F') cout<<"1111";
	else cout<<"1110";
	return 0;
}
