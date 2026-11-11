#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,m,a[N],cnt[31],flag[31][N],ansflag[31][N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] & 1)cnt[0]++;
	}
	
	sort(a+1,a+1+n,greater<int>());
	
	for(int i = (1 << 30),num = 30;num > 0;i >>= 1,num--)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[j] & i)
			{
				flag[num][j] = 1;
				cnt[num]++;
			}
		}
	}
	int ans = INT_MAX;
	bool firstflag = 0,y = 0;
	int num = 30;
	int x = 0;
	for(;num > 0;num--)
	{
		int count = 0;
		if(cnt[num] >= m)
		{
			for(int j = 1;j <= n;j++)
			{
				if(flag[num][j])
				{
					if(!firstflag)
					{
						x = num;
						ansflag[num][j] = 1;
					}
					else
					{
						if(ansflag[num+1][j] == 1)
						{
							ansflag[num][j] = 1;
							count++;
						}
					}
				}
			}
			if(count == m)
			{
				y = 1;
				break;
			}
			if(!firstflag)firstflag = 1;
		}
	}
	
	for(int i = 1,count = 0;i <= n,count <= m;count++,i++)
	{
		if(y == 1)
		{
			if(ansflag[num][i])ans &= a[i];
		}
		else
		{
			if(ansflag[x][i])ans &= a[i];
		}
	}
//	for(int j = 1;j <= n;j++){for(int num = 30;num > 0;num--)cout << ansflag[num][j] << " ";cout << endl;}
	cout << ans;
	return 0;
}
