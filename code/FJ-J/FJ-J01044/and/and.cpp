//and
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	long long cnt=n,ans=0;
	for(int j=30;j>=1;j--)
	{
		int tot=0;
		for(int i=1;i<=cnt;i++)
		{
			if(((a[i])>>(j-1))&1)
			tot++;
		}
		if(tot>=m)
		{
			ans+=(long long)((pow(2,j-1)));
			int op=0;
			for(int i=1;i<=cnt;i++)
			{
				if(((a[i])>>(j-1))&1)
				a[++op]=a[i];
			}
			cnt=op;
		}
	}	
	cout<<ans;
	return 0;
}
