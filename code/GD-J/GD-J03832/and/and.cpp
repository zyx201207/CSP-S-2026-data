#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
bool f[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=(1<<29); i>0; i=(i>>1))
	{
		int sum=0;
		for(int j=1; j<=n; ++j)
		{
			if(!f[j]&&(a[j]&i)) sum++;
		}
		if(sum>=m)
		{
			for(int j=1; j<=n; ++j)
			{
				if(!f[j]&&!(a[j]&i)) f[j]=1;
			}
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}

