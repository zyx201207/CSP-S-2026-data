#include<bits/stdc++.h>
using namespace std;

struct tic{
	int tn;
	int sn;
	char c;
}a,b;
int c1,c2;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a.tn = c1,b.tn = c2;
	a.sn = (s1[0] - '0') * 10 + s1[1] - '0',b.sn = (s2[0] - '0') * 10 + s2[1] - '0';
	a.c = s1[2],b.c = s2[2];
	if(a.tn == b.tn ){
		cout<<1;
	}
	else{
		cout<<0;
	}if(a.sn == b.sn && a.tn == b.tn) cout<<1;
	else cout<<0;
	if(a.sn == b.sn && a.tn == b.tn && ((a.c == 'A' || a.c == 'B' || a.c == 'C') && (b.c == 'A' || b.c == 'B' || b.c == 'C')) || ((a.c == 'E' || a.c == 'F') && (b.c == 'E' || b.c == 'F'))) cout<<1;
	else cout<<0;
	if(a.sn == b.sn && a.tn == b.tn && ((a.c == 'A' || a.c == 'B' || a.c == 'C') && (b.c == 'A' || b.c == 'B' || b.c == 'C')) || ((a.c == 'E' || a.c == 'F') && (b.c == 'E' || b.c == 'F')) && abs((a.c - '0') - (b.c - '0')) == 1) cout<<1;
	else cout<<0; 
	return 0;
}
