#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{  
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	int cs=1;
	while(m>=cs)
	{
		m-=cs;
		for(int i=1; i<=cs; i++)
		{
			a[i]++;
		}
		while(cs<n && a[cs]==a[cs+1])
		{
			cs++;
		}
	}
	cout<<cs<<endl;
	return 0;
}
