#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1;
	else cout<<0;
	char t1=s1[2],t2=s2[2];
	if(((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C') || (t1>='D'&&t1<='F'&&t1>='D'&&t1<='F'))&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1;
	else cout<<0;
	if( ((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t2=='A'&&t1=='B')||(t2=='B'&&t1=='C')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D') ) && (s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)) cout<<1;
	else cout<<0;
	return 0;
}
