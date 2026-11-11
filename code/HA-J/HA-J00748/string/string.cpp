#include<bits/stdc++.h>
using namespace std;
int a[300000];
char c[300000];
string s;
int n;
long long l,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=a[i]*c[i];
		l=l+a[i];
	}
	int sd=l/2;
	for(int i=1;i<=sd;i++)
	{
		if(s[i]!=s[l-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
