#include<bits/stdc++.h>
using namespace std;
int n,h;
char c[200005];
long long a[200005],ans,sum,s[200005],an;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ans+=a[i];
		s[i]=s[i-1]+a[i];
	}
	ans/=2;
	sum=ans;
	cout<<ans;
	return 0;
}
