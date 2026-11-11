#include <bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
char c1,c2;
int a[10]={0,1,1,1,2,2};
bool flag=false;
int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	if(s1==s2)
	{
		cout<<1;
		flag=true;
	} 
	else cout<<0;
	
	if(flag && ss1[ss1.size()-2]==ss2[ss2.size()-2] && ss1[ss1.size()-3]==ss2[ss2.size()-3]) cout<<1;
	else
	{
		cout<<0;
		flag=false;
	} 
	
	if(flag &&  a[ss1[ss1.size()-1]-64]==a[ss2[ss2.size()-1]-64]) cout<<1;
	else
	{
		cout<<0;
		flag=false;
	}
	
	if(ss1[ss1.size()-1]>ss2[ss2.size()-1])
	{
		c1=ss2[ss2.size()-1],c2=ss1[ss1.size()-1]; 
	}
	else
	{
		c1=ss1[ss1.size()-1],c2=ss2[ss2.size()-1];
	}
	if(flag && ((c1=='A' && c2=='B') || (c1=='B' && c2=='C') || (c1=='D' && c2=='F'))) cout<<1;
	else cout<<0;
 } 
