#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005];
bool k[300005];
stack<int> f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		while(f.empty()) f.pop();
		for (int j=1;j<=m;j++) k[j]=0;
		for (int j=i;j<=n;j++)
		{
			if (k[a[j]])
			{
				while(f.top()!=a[j]) f.pop();
				f.pop();
				k[a[j]]=0;
			}
			else f.push(a[j]),k[a[j]]=1;
		}
		for (int j=1;j<=m;j++) if (k[j]) s[j]++;
	}
	
	for (int i=1;i<=m;i++) cout<<s[i];
	return 0;
}
