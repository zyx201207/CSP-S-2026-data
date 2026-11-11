#include <bits/stdc++.h>
using namespace std;
bool checkl(char a,char b)
{
	if((a=='D' && b=='F') || (a=='F' && b=='D')) return 1;
	if(a=='D' || a=='F' || b=='D' || b=='F') return 0;
	return 1;
}
bool checkl2(char a,char b)
{
	if(a=='A' && b=='B') return 1;
	else if(a=='B' && b=='A') return 1;
	else if(a=='B' && b=='C') return 1;
	else if(a=='C' && b=='B') return 1;
	else if(a=='D' && b=='F') return 1;
	else if(a=='F' && b=='D') return 1;
	return 0;
}
bool check1(int a,int b)
{
	if(a==b) return 1;
	return 0;
}
bool check2(int a,int p1,int b,int p2)
{
	if(a==b && p1==p2) return 1;
	return 0;
}
bool check3(int a,int p1,char l1,int b,int p2,char l2)
{
	if(a==b && p1==p2 && checkl(l1,l2)) return 1;
	return 0;
}
bool check4(int a,int p1,char l1,int b,int p2,char l2)
{
	if(a==b && p1==p2 && checkl2(l1,l2)) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s1,s2;
	cin >> n >> s1 >> m >> s2;
	char l1,l2;
	l1=s1[s1.size()-1];
	l2=s2[s2.size()-1];
	int p1=0,p2=0;
	for(int i=0;i<=1;i++)
	{
		p1=p1*10+(s1[i]-'0');
		p2=p2*10+(s2[i]-'0');
	}
	cout << check1(n,m) << check2(n,p1,m,p2) << check3(n,p1,l1,m,p2,l2) << check4(n,p1,l1,m,p2,l2);
	return 0;
}
//O(1)
