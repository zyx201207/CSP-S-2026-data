#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m;
struct fw
{
	int v;
	int a[33];
	bool fl;
}f[N];
int p[33],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i].v ;
		int t = 0,u = f[i].v;
		while(u)
		{
			int w = u % 2;
			f[i].a[t] = w;
			t++;
			u /= 2;
		}
		f[i].fl = 1;
	}
	p[0] = 1;
	for(int i=1;i<=30;i++)
	{
		p[i] = p[i-1] * 2;
	}
	for(int k=29;k>=0;k--)
	{
		int cnt= 0;
		for(int i=1;i<=n;i++)
		{
			if(f[i].fl == 0) continue;
			if(f[i].a[k])
			{
				cnt++;	
			}
//			else
//			{
//				f[i].fl = 0;
//			}
		}
		if(cnt >= m)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i].a[k] == 0)
				{
					f[i].fl = 0;
				}
			}
			ans += p[k];
		}
	}
	cout<<ans;
	return 0;
} 
