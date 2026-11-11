#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool v[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(v,1,sizeof(v));
	for(int j=31;j>=0;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(v[i])
				cnt+=(a[i]>>j)&1;
		if(cnt>=m)	
			for(int i=1;i<=n;i++)
				if(v[i])
					v[i]=(a[i]>>j)&1;
	}
	int ans=~0u>>1;
	for(int i=1;i<=n;i++)
		if(v[i])
			ans&=a[i];
	cout<<ans;
	return 0;
}
