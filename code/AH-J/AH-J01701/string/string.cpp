#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s=s+c;
		}
	}
	int si=s.size();
	for(int i=0;i<si/2;i++)
	{
		if(s[i]!=s[si-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
