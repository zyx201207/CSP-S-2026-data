#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005],js[10000005];
bool c[10000005];
queue<long long>b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		for(int j=i;j<=n;j++)
		{
			b.push(a[j]);
			if(b.front()==b.back()&&b.size()!=1)
			{
				while(b.front()!=b.back())
				b.pop();
			}
			js[a[j]]++;
			if(b.front()==b.back()&&b.size()!=1)
			{
				js[a[j]]=n;
			}
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<js[a[i]]<<' ';
	}
	return 0;
}
