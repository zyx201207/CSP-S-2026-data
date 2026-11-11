#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string r1,r2,s1,s2;
int a=0,b=0,c=0,d=0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1) {
		a=1;
		if(r2[0]==s2[0]&&r2[1]==s2[1]) {
			b=1;
			if(r2[2]<='C'&&s2[2]<='C') {
				c=1;
				if(r2[2]=='A'&&s2[2]=='B'||r2[2]=='B'&&s2[2]=='C'||r2[2]=='B'&&s2[2]=='A'||r2[2]=='C'&&s2[2]=='B'||r2[2]=='D'&&s2[2]=='F'||r2[2]=='F'&&s2[2]=='D') {
					d=1;
				}
			} else if(r2[2]>='D'&&s2[2]>='D') {
				c=1;
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
