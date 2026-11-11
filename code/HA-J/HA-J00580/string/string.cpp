#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],ans;
char b;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>b;
		while(a[i]>0)
		{
			s+=b;
			a[i]=a[i]-1;
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
