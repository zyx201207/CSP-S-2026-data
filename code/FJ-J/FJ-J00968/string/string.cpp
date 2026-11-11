#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long m;
		char ch;
		cin>>m; 
		cin>>ch;
		for(int i=1;i<=m;i++)s+=ch;
	}	
	long long l=0,r=s.size()-1;
	if(s.size()%2==0)
	{
		while(l<r)
		{
			if(s[l]!=s[r])
			{
				ans++;
				l++;
				r--;
			}
			else
			{
				l++;
				r--;	
			}
		}		
	}
	else
	{
		while(l<=r)
		{
			if(s[l]!=s[r])
			{
				ans++;
				l++;
				r--;
			}
			else
			{
				l++;
				r--;	
			}
		}
	}
	cout<<ans;
	return 0;
} 
