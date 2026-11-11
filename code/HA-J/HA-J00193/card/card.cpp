#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005];
int s[500005];
int cnt[300005];
int top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		top=0;
		vector<bool> f(m,0);
		for(int j = i;j<=n;j++)
		{
			if(f[a[j]])
			{
				while(s[top]!=a[j]&&top>0)
				{
					f[s[top]]=0;
					top--;
				}
				if(top>0)
				{
					f[s[top]]=0;
					top--;
				}
			}
			s[++top]=a[j];
			f[a[j]]=1;
		}
		for(int j =1;j<=top;j++)
		{
			cnt[s[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] <<" ";
	}
	return 0;
}
