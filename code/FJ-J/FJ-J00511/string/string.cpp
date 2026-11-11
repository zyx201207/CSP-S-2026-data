#include<bits/stdc++.h> 
using namespace std;
int n,ans;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x>>c[i];
		for(int j=1;j<=x;j++)
		{
			s+=c[i];
		}
	}
	
	
	long long l=s.length()-1;
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
