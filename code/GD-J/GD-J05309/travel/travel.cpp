#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=c[i])
		{
			cout<<'0'<<'0'<<'0'<<'0';
			return 0;
		}
	}
	cout<<'1';
	if(b[0]!=d[0]||b[1]!=d[1])
	{
		cout<<'0'<<'0'<<'0';
		return 0;
	}
	cout<<'1';
	if(b[2]=='A')if(d[2]=='B'||d[2]=='C')cout<<'1',t=1;
	if(b[2]=='B')if(d[2]=='A'||d[2]=='C')cout<<'1',t=1;
	if(b[2]=='C')if(d[2]=='B'||d[2]=='A')cout<<'1',t=1;
	if(b[2]=='D'&&d[2]=='F')cout<<'1',t=1;
	if(b[2]=='F'&&d[2]=='D')cout<<'1',t=1;
	if(t==0)
	{
		cout<<'0'<<'0';
		return 0;
	}
	if(abs(int(b[2])-int(d[2]))==1)
	{
		if((b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B'))cout<<'0';
		else cout<<'1';
	}
	else cout<<'1';
	
	
	return 0;
}
