#include<bits/stdc++.h>
#define il inline
using namespace std;
int len1,len2,p1,p2,z1,z2;
string c1,s1,c2,s2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	len1=s1.size();len2=s2.size();
	for(int i=0;i<len1;i++) {
		if(s1[i]>='0' && s1[i]<='9')
			p1=(p1<<3)+(p1<<1)+(s1[i]^48);
		else z1=s1[i];
	}
	for(int i=0;i<len2;i++) {
		if(s2[i]>='0' && s2[i]<='9')
			p2=(p2<<3)+(p2<<1)+(s2[i]^48);
		else z2=s2[i];
	}
	if(p1==p2) {
		cout<<1;
		if(z1=='D' || z1=='F') {
			if(z2=='D' || z2=='F') cout<<1<<1;
			else cout<<0<<0;
		}else {
			if(z2=='A' || z2=='B' || z2=='C') {
				cout<<1;
				if(z1>z2) swap(z1,z2);
				if(z1=='A' && z2=='C') cout<<0;
				else cout<<1;
			}else {
				cout<<0<<0;
				return 0;
			}
		}
	}else {
		cout<<"000";
		return 0;
	}
	return 0;
}
