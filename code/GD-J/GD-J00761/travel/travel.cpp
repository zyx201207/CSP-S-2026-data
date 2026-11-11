#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string t1,t;
	t1=s1[0]+s1[1],t=s2[0]+s2[1];
	cout<<(c1==c2)<<(t1==t and c1==c2);
	if((c1==c2) and (t1==t) and (s1[2]<='C' and s2[2]<='C') or (s1[2]>'C' and s2[2]>'C')) cout<<1;
	else cout<<0;
	if((c1==c2) and (t1==t) and (s1[2]!='C' and s2[2]!='D') and (s1[2]+1==s2[2] or s1[2]-1==s2[2]) and (s1[2]!='D' and s2[2]!='C')) cout<<1;
	else cout<<0;
	return 0;
} 
