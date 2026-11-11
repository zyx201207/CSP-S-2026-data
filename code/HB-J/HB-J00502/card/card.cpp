#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s[500005];
int ans[500005];
int top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=top;k++)
				if(s[k]==a[j])
				{
					top=k-1;
					cout<<a[i]<<"\n";
					break;
				}
			s[++top]=a[j];
		}
		for(int j=1;j<=top;j++)
			cout<<s[j]<<" ";
		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
