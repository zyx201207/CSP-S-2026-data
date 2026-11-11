#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
long long a[N],c[N];
long long sum,ans;
string s;
long long n,l;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=a[i];k++)
		{
			for(int j=sum;j<=a[i]+sum;j++)
			{
				s[j]=c[i];
				sum+=a[i];
			}
		}
	}
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]!=s[s.size()]+1-i)
		{
			ans++;	
		}
	}
	cout<<ans;
	return 0;
}
