#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b)
{
	bool x=(a=='A'||a=='B'||a=='C'),y=(b=='A'||b=='B'||b=='C');
	return x==y;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool q1=(c1==c2),q2=(s1[0]==s2[0]&&s1[1]==s2[1]);
	cout<<q1<<(q2&&q1);
	bool q=(q1&&q2&&check(s1[2],s2[2]));
	cout<<q;
	cout<<(q&&abs(s1[2]-s2[2])==1);
	return 0;
}
