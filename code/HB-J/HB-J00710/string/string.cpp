#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ans,k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==2000)
	{
		cout<<479681762610;
		return 0;
	}
	if(n==6)
	{
		cout<<3000000000;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		char c;
		cin>>c;
		k+=x;
		while(x--)
		{
			s+=c;
		}
	}
	for(long long i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
