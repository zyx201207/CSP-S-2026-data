#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n,m;
int a[N];
int _max = -INT_MAX;
int ans,x,b;
void cp()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			int y = a[i] & a[j];
			//cout<<y<<endl;
			if(_max < y)
			{
				_max = y;
				x = i;
				b = j;
			} 
		}
	}
}
int main()
{
	cin>>n>>m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 2;i <= m;i++)
	{
		_max = -INT_MAX;
		cp();
		for(int j = x;j<n;j++)
		{
			a[j] = a[j+1];
		}
		for(int j = b;j<n;j++)
		{
			a[j] = a[j+1];
		}
	}
	cout<<_max;
	return 0;
}