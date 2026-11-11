#include<bits/stdc++.h>
using namespace std;

double e[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans=0,d=0,n,m;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		for(int i=1;i<=m;i++)
		{
			d++;
			e[d]=a;
		}
	}
	int j=d;
	for(int i=1;i<=d/2;i++)
	{
		if(e[i]!=e[j])
		{
			ans++;
		}
		j--;
	}
	cout<<ans<<'\n';
	
	return 0;
}
