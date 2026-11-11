#include<bits/stdc++.h>
using namespace std;
int cx1,cx2;
int pai1,pai2;
char wz1,wz2;
bool check1(char a,char b)
{
	if(((a>='A' && a<='C') && (b>='A' && b<='C')) || ((a>='D' && a<='F') && (b>='D' && b<='F')))
		return 1;
	return 0;
}
bool check2(char a,char b)
{
	if(((a>='A' && a<='C') && (b>='A' && b<='C') && abs(a-b)==1) || ((a>='D' && a<='F') && (b>='D' && b<='F') && abs(a-b)==2))
		return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>cx1>>pai1>>wz1;
	cin>>cx2>>pai2>>wz2;
	bool f1=(cx1==cx2),f2=(f1 && pai1==pai2);
	bool f3=(f2 && check1(wz1,wz2));
	bool f4=(f3 && check2(wz1,wz2));
	cout<<f1<<f2<<f3<<f4<<'\n';
	return 0;
}