#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[100005];
int b[1005][1005];
int c[100];
int maxx = -0x3f3f;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    for(int i = 0;i<n;i++)
    {
		cin>>a[i];
		int xx = a[i];
		int st = 0;
		while(xx != 0)
		{
			b[i][st] = xx%2;
			xx/=2;
			st++;
		}
	}
	if(m == 1)
	{
		sort(a, a+n);
		cout<<a[n-1];
		return 0;
	}
	for(int i = 0;i<maxx;i++) 
	{
		c[i] = b[0][i];
	}
	if(n == m)
	{
		for(int i = 1;i<n;i++)
		{
			for(int j = 0;j<maxx;j++)
			{
					if(c[i] == b[i][j])
					{
						c[j] = 1;
					}
					else c[j] = 0;
			}
		}
	}
	cout<<maxx;
	return 0;
}
