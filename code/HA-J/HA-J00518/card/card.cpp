#include <bits/stdc++.h>
#include <unordered_map> 
using namespace std;

int n,m,a[500005],b[300005];

unordered_map<int, int> mp_pai;  // 牌号 --> 下标 
unordered_map<int, int> mp_xb;	//   下标 --> 牌号 

void solve(int i)
{
	mp_pai.clear();
	mp_xb.clear();
	int cnt=1;
	for(int j=i-1;j<n;j++)
	{
		if(mp_pai[a[j]] != 0)
		{
			int xb = mp_pai[a[j]];
			for(int k=xb;k<cnt;k++)
			{
				int pai = mp_xb[k];
				mp_pai[pai] = 0;
				mp_xb[k] = 0;
			}
			cnt = xb;
		}
		mp_pai[a[j]] = cnt;
		mp_xb[cnt] = a[j];
		cnt++;
	}
	for(int w=1;w<=m;w++)
	{
		if(mp_pai[w] != 0) b[w]++;
	}
}


int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		solve(i);
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

