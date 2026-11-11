#include<bits/stdc++.h>
using namespace std;
long long l,r;
char s[20000005];
int main()
{
	freopen("string.in","stdin","r");
	freopen("string.out","stdout","w");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char a;
		cin>>x>>a;
		l+=x;
		for(long long j=0;j<l;j++)
		{
			s[r]=a;
			r++;
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]==s[l+1-i]) ans+=0;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}
