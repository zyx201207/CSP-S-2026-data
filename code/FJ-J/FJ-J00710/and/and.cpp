#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int a[100100];
	for(int i=1;i<=n;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n,greater<int>());
	if(n==m)
	{
		for(int i=2;i<=n;i++)
		{
			
			k&=a[i];
		}
		cout<<k;
	}
	else if(m==1)
	{
		cout<<a[1];
	}
	else
	{
		cout<<a[n-m+1];
	}
	return 0;
}

