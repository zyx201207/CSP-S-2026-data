#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1="",a2="",b1="",b2="";
	cin>>a1>>a2>>b1>>b2;
	bool bl1=(a1==b1);
	bool bl2=false,bl3=false,bl4=false;
	if(bl1) {
		string p1=a2.substr(0,2),p2=b2.substr(0,2);
		bl2=(p1==p2);
		if(bl2) {
			char c1=a2[2],c2=b2[2];
			bl3=((c1>='D' && c2>='D') || (c1<='C' && c2<='C'));
			if(bl3) bl4=(abs(c1-c2)==1);
			if((c1=='D' && c2=='F') || (c1=='F' && c2=='D')) bl4=true;
		}
	}
	cout<<bl1<<bl2<<bl3<<bl4;
	
	return 0;
}
