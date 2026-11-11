#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	long long n=a.size();
	for(long long i=0;i<n;i++)
	{
		if(a[i]!=c[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	long long m=b.size();
	for(long long i=0;i<m-1;i++)
	{
		if(b[i]!=d[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')
	{
		if(d[2]=='D'||d[2]=='E')
		{
			cout<<"1100";
			return 0;
		}
	}
	else if(b[2]=='D'||b[2]=='E')
	{
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(abs(d[2]-b[2])==1) cout<<"1111";
	else cout<<"1110";
	return 0;
 } 
