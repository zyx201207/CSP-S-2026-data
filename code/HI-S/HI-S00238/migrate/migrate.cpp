#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
long long land[N];
int arri[N][N];
int n, k;
void sch(int ori, int now, int len)
{
	for(int i = now + 1; i <= n; i++)
	{
		if(land[i] - land[now] > k) return;
		if(len + 1 <= (land[i] - land[ori] + k - 1) / k) arri[ori][i]++; 
		sch(ori, i, len + 1);
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				arri[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			cin>>land[i];
		}
		for(int i = 1; i <= n; i++)
		{
			sch(i, i, 0);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(arri[i][j] == 2) ans++;
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
