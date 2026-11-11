//GZ-J00114 ÍõÕıÅí 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void check(char c1,char c2)
{
	if(c1=='A')
	{
		if(c2=='B')
			cout<< "11";
		if(c2=='C')
			cout<< "10";
		if(c2=='D'||c2=='E')
			cout<< "00";
	}
	if(c1=='B')
	{
		if(c2=='A'||c2=='C')
			cout<< "11";
		if(c2=='D'||c2=='E')
			cout<< "00";
	}
	if(c1=='C')
	{
		if(c2=='A')
			cout<< "10";
		if(c2=='B')
			cout<< "11";
		if(c2=='D'||c2=='E')
			cout<< "00";
	}
	if(c1=='D'||c1=='E')
	{
		if(c2=='A'||c2=='B'||c2=='C')
			cout<< "00";
		else
			cout<< "11";
	}
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c1,c2;
	string s1,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	ll p1=(s1[0]-'0')*10+(s1[1]-'0');
	ll p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2)
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	} 
	char z1=s1[2],z2=s2[2];
	check(z1,z2);
	return 0;
}
