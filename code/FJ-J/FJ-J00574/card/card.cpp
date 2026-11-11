#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005];
unordered_set<int>b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m;
	bool k=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=a[i-1])
			k=0;
	}
	if(k)
	{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(a[j]!=a[j-1]||j==i)
					s[a[j]]++;
		for(int i=1;i<=m;i++)
			cout<<s[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool bj[300005]{};
		for(int j=i+1;j<=n;j++)
			bj[a[j]]=1;
		for(int j=1;j<i;j++)
			if(bj[a[j]])
				b[i].insert(j);
	}
	for(int i=1;i<=n;i++)
	{
		bool bj[300005]{},noend[500005]{};
		for(int j=i;j<=n;j++)
			if(!bj[a[j]])
			{
				for(int x:b[j])
					if(x>=i&&noend[x])
						goto end;
				s[a[j]]++;
				noend[j]=1;
				bj[a[j]]=1;
				end:;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	return 0;
}
