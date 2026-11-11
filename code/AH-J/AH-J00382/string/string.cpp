#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=cnt;j<a[i]+cnt;j++)
		{
			s=s+c[i];
		}
		cnt+=a[i];
	}
	long long ans=0;
	for(int i=0;i<ceil(s.size()/2);i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
