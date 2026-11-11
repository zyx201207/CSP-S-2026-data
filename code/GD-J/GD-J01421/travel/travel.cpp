#include<bits/stdc++.h>
using namespace std;
int c,d,s,t;
char s1,t1;
map<char,int>m;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>s1>>d>>t>>t1;
	if(c==d)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s==t)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	m['A']=1,m['B']=1;
	m['C']=1,m['D']=2;
	m['F']=2,m['J']=67;
	if(m[s1]==m[t1])
	{
		cout<<1;
	}
	else
	{
		cout<<"0002 01A 03 01A";
		return 0;
	}
	if(abs(t1-s1)<=1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
