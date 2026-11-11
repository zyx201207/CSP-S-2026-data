#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans=0;
void p()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	while(m--)
	{
		a[0]++;
		p();
	}
	for(int i=0;i<n;i++)
	{
		if(a[0]==a[i]) ans++;
	}
	cout<<ans;
	return 0;
}
