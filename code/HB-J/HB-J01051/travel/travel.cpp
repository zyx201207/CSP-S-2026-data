#include<bits/stdc++.h>
using namespace std;
bool ce(char a,char b)
{
	if(a=='A'||a=='B'||a=='C')
		if(b=='A'||b=='B'||b=='C')
			return true;
	if(a=='D'||a=='E')
		if(b=='D'||b=='E')
			return true;
	return false;
}
bool lin(char a,char b)
{
	if(a==b+1||a==b-1) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int q=0,w=0,e=0,r=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) q=1;
	char set1=s1[2],set2=s2[2];
	int te1=0,te2=0;
	for(int i=0;i<2;i++)
	{
		te1=te1*10+s1[i];
		te2=te2*10+s2[i];
	}
	if(q&&te1==te2) w=1;
	if(w&&ce(set1,set2)) e=1;
	if(e&&lin(set1,set2)) r=1;
	cout<<q<<w<<e<<r;
	return 0;
}
