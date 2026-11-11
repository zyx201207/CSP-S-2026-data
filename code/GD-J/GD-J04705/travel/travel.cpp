#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	cin>>c1>>s1>>c2>>s2;
	bool r1=(c1==c2),r2=(s1[0]==s2[0]&&s1[1]==s2[1]);
	bool r3=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));
	bool r4=(!(s1[2]=='C'&&s2[2]=='A')&&!(s1[2]=='A'&&s2[2]=='C'));
	cout<<r1<<(r1&&r2)<<(r1&&r2&&r3)<<(r1&&r2&&r3&&r4);
	return 0;
}
