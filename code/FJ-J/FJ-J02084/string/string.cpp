#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b=1;
	string s="";
	cin>>n;
	vector<long long> a(n+1);
	vector<char> c(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	long long l=0,r=s.size()-1,ans=0;
	while(l<=r)
	{
		if(s[l]!=s[r]) 
		{
			ans++;
		}
	    l++;
		r--;
	}
	cout<<ans;
	return 0;
}
