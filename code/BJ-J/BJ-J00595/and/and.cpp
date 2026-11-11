#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool f[N],st[N];
char c[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i]=1;
	int ans=0;
	for(int k=30;k>=0;k--)
	{
		for(int i=1;i<=n;i++) st[i]=1;
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i] && ((a[i]>>k)&1)) now++;
			else if(f[i])st[i]=0;
		}
		if(now>=m) 
		{
			ans+=(1<<k);
			for(int i=1;i<=n;i++)
			{
				if(st[i]==0) f[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
