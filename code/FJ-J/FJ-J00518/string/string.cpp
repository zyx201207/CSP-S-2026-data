#include <bits/stdc++.h>
using namespace std;
int n;
char ch[200005];
long long a[200005],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		a[i]+=a[i-1];
	}
	for(long long i=1;i<=a[n]/2;i++)
	{
		long long j=a[n]-i+1;
		int x=lower_bound(a+1,a+n+1,i)-a;
		int y=lower_bound(a+1,a+n+1,j)-a;
		if(ch[x]!=ch[y]) ans++;
	}
	cout<<ans;
	return 0;
}
