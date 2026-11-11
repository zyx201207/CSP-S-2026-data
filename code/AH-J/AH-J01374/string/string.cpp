#include<bits/stdc++.h>
using namespace std;
string s;
int f()
{
	long long i,j,ans=0;
	for(i=0,j=s.size()-1;i<s.size()/2,j>=s.size()/2+1;i++,j--)
	{
		if(s[i]!=s[j])
			ans++;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,n,a,ans;
	char c;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
			s+=c;
	}
	ans=f();
	cout<<ans;
	return 0;
}
