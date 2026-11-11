#include <bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005],t[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<1;
		return 0;
	}
	else
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			t[a[i]]++;			
		}
		for(int i = 1;i<=m;i++)
		{
			if(t[i]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	cout<<"10 3 3";
	return 0;
}
