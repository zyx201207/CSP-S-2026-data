#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
bool check(char x,char y)
{
	if(x=='A')
	{
		return y=='B' || y=='C';
	}
	else if(x=='B')
	{
		return y=='A' || y=='C';
	}
	else if(x=='C')
	{
		return y=='A' || y=='B';
	}
	else if(x=='D')
	{
		return y=='F';
	}
	else if(x=='F')
	{
		return y=='D';
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1, a2, b1, b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	string ta=to_string(a2[0]+a2[1]);
	string tb=to_string(b2[0]+b2[1]);
	if(ta!=tb)
	{
		cout<<"1000";
		return 0;
	}
	char A=a2[2], B=b2[2];
	if(check(A,B)==0)
	{
		cout<<"1100";
		return 0;
	}
	if(abs(A-B)==1)
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		cout<<"1110";
		return 0;
	}
	return 0;
}
