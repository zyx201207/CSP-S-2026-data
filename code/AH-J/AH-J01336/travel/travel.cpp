#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long p1,p2,id1,id2,f1,f2,f3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<"1";
		f1=1;
	}
	else
	{
		cout<<"0";
	}
	if (f1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
		f2=1;
	}
	else
	{
		cout<<"0";
	}
	id1=s1[2]-'A';
	id2=s2[2]-'A';
	if (f2&&id1>=0&&id1<=2&&id2>=0&&id2<=2)
	{
		cout<<"1";
		f3=1;
	}
	else if (f2&&id1>=3&&id1<=4&&id2>=3&&id2<=4)
	{
		cout<<"1";
		f3=1;
	}
	else
	{
		cout<<"0";
	}
	if (f3&&abs(id1-id2)==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
