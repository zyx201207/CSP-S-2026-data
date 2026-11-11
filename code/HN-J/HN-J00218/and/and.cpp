#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;++i) cin>>a[i];
	
	if(m==1)
	{
		sort(a.begin(),a.end());
		cout<<a[n];
		return 0;
	}
	else if(m==n)
	{
		for(int i=2;i<=n;++i)
		{
			a[1]=a[1]&a[i];
		}
		cout<<a[1];
		return 0;
	}
	else if(m==2)
	{
		sort(a.begin(),a.end());
		a[n]=a[n]&a[n-1];
		cout<<a[n];
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=2;i<=n;++i)
		{
			a[2]=a[2]&a[i];
		}
		cout<<a[2];
		return 0;
	}
	else 
	{
		int k=1;
		sort(a.begin(),a.end());
		for(int i=n-1;i>=0;--i)
		{
			if(k<m)
			{
				a[n]=a[n]&a[i];
				k++;
			}
			else break;
		}
		cout<<a[n];
	}
	
	return 0;
}
