#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+7;

int n,m;
int maxx = -1;
int a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				maxx = max(maxx,a[i] & a[j]);
				//cout <<(a[i]&a[j])<<" "<<a[i]<<" "<<a[j]<<endl;
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == 1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if(m == n)
	{
		int ans = a[1];
		for(int i = 1;i<=n;i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}/*
	if(m == (n-1))
	{
		return 0;
	}*/
	int ans[N] = {0};
	for(int i = 1;i<=n;i++)
	{
		ans[i] = a[i];
		for(int j = i;j<=i+m;j++)
		{
			ans[i] &= a[j];
		}
	}
	maxx = -100;
	for(int i = 1;i<=n;i++)
	{
		maxx = max(maxx,ans[i]);
	}
	cout << maxx;
	return 0;
}
