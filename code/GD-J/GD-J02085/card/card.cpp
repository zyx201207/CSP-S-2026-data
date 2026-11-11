#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],b[300005],ans[300005],del;
bool f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(int I=1;I<=n;I++)
	{
		for(int i=1;i<=m;i++)
		b[i]=s[i];
		for(int i=I;i<=n;i++)
		{
			if(f&&del==a[i])
			{
				if(b[a[i]]==1)
				{
					f=false;
					b[a[i]]--;
					ans[a[i]]++;
				}
				else b[a[i]]--;
				continue;
			}
			if(f)
			{
				b[a[i]]--;
				continue;
			}
			if(!f&&b[a[i]]>=2)
			{
				f=true;
				del=a[i];
				b[a[i]]--;
				continue;
			}
			if(!f)ans[a[i]]++;
		}
		s[a[I]]--;
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}

