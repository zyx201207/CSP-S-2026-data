#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],c[300005];
string k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if((b[a[j]]-1)!=0)
			{
				k.clear();
				b[a[j]]--;
			}	
			k=k+char(a[j]+'0');
		}
		for(int j=0;j<k.size();j++)
		{
			c[(k[j]-'0')]++;
		}
		for(int j=1;j<=m;j++)
		{
			b[j]=0;
		}
		k.clear();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
