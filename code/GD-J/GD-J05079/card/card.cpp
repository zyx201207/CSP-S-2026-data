#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2e5+10; 
ll n,m,a[N],ans[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool fA=true;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i] > a[i+1])
		{
			fA=false;
		}
	}
	if(m==2)
	{
		int id1=0,id2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				id1=max(id1,i);
			}
			if(a[i]==2)
			{
				id2=max(id2,i);
			}
		}
		cout << id1 << ' ' << id2 << endl;
	}
	else if(fA==true)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		
	}
	return 0;
}
