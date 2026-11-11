#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[200005];
	long long cnt=0,b,a[200005],ans=0,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	b=cnt/2;
	cnt/=2;
	for(i=1;i<=cnt;i++)
	{
		if(c[i]!=c[b]) ans++;
		b--;
	}
	cout<<ans<<endl;
	return 0;
}
