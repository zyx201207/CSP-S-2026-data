//GZ-J00296，贵阳市南明区李端棻中学，任柏翰 
#include<bits/stdc++.h>
using namespace std; 

const int N=2*1e5+5;  
int n;
long long ans=0;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		char c;
		cin>>cnt>>c;
		for(int _=1;_<=cnt;_++)
		{
			s+=c;
		}
	}
	l=s.size();
	s=' '+s;
	for(int i=1;i<=l/2;i++)
	{
		int r=l-i+1;
		if(s[i]!=s[r])
			ans++;
	}
	cout<<ans;
	
	return 0;
}
