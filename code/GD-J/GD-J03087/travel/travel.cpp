#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
map<char,int>mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['F']=1;mp['D']=1;
	mp['A']=0;mp['B']=0;mp['C']=0;
	cin>>a>>x>>b>>y;
	cout<<(a==b);
	cout<<((a==b)&&(x.substr(0,2)==y.substr(0,2)));
	cout<<((a==b)&&(x.substr(0,2)==y.substr(0,2))&&
	(mp[x[2]]==mp[y[2]]));
	cout<<((a==b)&&(x.substr(0,2)==y.substr(0,2))&&
	(mp[x[2]]==mp[y[2]])&&(1==abs((x[2]-'0')-(y[2]-'0'))));
	return 0;
} 
