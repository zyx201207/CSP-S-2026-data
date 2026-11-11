#include<bits/stdc++.h>
using namespace std;
//#define ll long long
string c1,s1,c2,s2;
int Rs;
int Xs;
bool sameCar()
{
	return (c1==c2);
}
bool sameRow()
{
	if(!sameCar())
		return 0;
	return (s1[0]==s2[0] and s1[1]==s2[1]);
}
bool sameSide()
{
	if(!sameCar())
		return 0;
	if(!sameRow())
		return 0;
	if(s1[2]>='A' and s1[2]<='C')
		return (s2[2]>='A' and s2[2]<='C');
	else
		return (s2[2]>='D' and s2[2]<='F');
}
bool isNear()
{
	if(!sameCar())
		return 0;
	if(!sameRow())
		return 0;
	if(!sameSide())
		return 0;
	if(s1[2]=='A')
		return (s2[2]=='B');
	else if(s1[2]=='B')
		return (s2[2]=='A' or s2[2]=='C');
	else if(s1[2]=='C')
		return (s2[2]=='B');
	else if(s1[2]=='D')
		return (s2[2]=='F');
	else
		return (s2[2]=='D');
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<sameCar()<<sameRow()<<sameSide()<<isNear();
	return 0;
}

