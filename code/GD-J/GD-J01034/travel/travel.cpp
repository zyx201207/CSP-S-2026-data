#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s1()
{
	return a==c?1:0;
}
int s2()
{
	return a==c&&b[0]==d[0]&&b[1]==d[1]?1:0;
}
int s3()
{
	if(!(a==c&&b[0]==d[0]&&b[1]==d[1])) return 0;
	if((b[2]-'A')/3==(d[2]-'A')/3) return 1;
	return 0;
}
int s4()
{
	if(!(a==c&&b[0]==d[0]&&b[1]==d[1])) return 0;
	if(!((b[2]-'A')/3==(d[2]-'A')/3)) return 0;
	char x=b[2],y=d[2];
	if(x>y) swap(x,y);
	if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F') return 1;
	return 0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	cout<<s1()<<s2()<<s3()<<s4();
	return 0;
}
