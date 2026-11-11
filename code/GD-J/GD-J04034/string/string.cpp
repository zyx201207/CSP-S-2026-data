#include <bits/stdc++.h>
using namespace std;long long a[100005];char b[100005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long x=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	string s,ss,sss;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
	{
		s+=b[i];
	}
 
	}
		for(int i=0;i<(s.size()-1)/2;i++)
		{
	if(s[i]!=s[s.size()-i-1])
		{
			x++;
		}
		}
		
	
cout<<x;
	
	
	
	
	
	return 0;
	
	}
