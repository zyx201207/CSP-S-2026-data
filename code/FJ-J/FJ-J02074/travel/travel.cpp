#include<bits/stdc++.h>
using namespace std;
string s1,s2,b1,b2,p1,p2,q1,q2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>b1>>s2>>b2;
	if(s1==s2) cout<<1;
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		exit(0);
	}
	p1=b1.substr(0,2);
	p2=b2.substr(0,2);
	q1=b1.substr(2,1);
	q2=b2.substr(2,1);
	if(p1==p2) cout<<1;
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		exit(0);
	}
	if(p1==p2)
	{
		if(q1=="A"&&q2=="B") cout<<1<<1;
		if(q1=="A"&&q2=="C") cout<<1<<0;
		if(q1=="B"&&q2=="A") cout<<1<<1;
		if(q1=="B"&&q2=="C") cout<<1<<1;
		if(q1=="C"&&q2=="A") cout<<1<<0;
		if(q1=="C"&&q2=="B") cout<<1<<1;
		if((q1=="D"&&q2=="E")||(q2=="D"&&q1=="E")) cout<<1<<1;
		if((q1=="C"||q1=="B"||q1=="A")&&(q2=="D"||q2=="E"))
		{
			cout<<0;
			cout<<0;
		}
		if((q2=="C"||q2=="B"||q2=="A")&&(q1=="D"||q1=="E"))
		{
			cout<<0;
			cout<<0;
		}
	}
	return 0;
}
