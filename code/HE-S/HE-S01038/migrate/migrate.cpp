#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
int a[2000005],cntt[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while(T--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		int ans = 0;
		if(C == 11 || C == 12)
		{
			for(int i = 1;i <= 1;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					cntt[j] = 0;
				}
				v.clear();
				int sum = 0;
				for(int j = i + 1;j <= n;j++)
				{
					sum += (a[j] - a[j - 1]);
					if(sum > d)
					{
						v.push_back(j - 1);
						sum = a[j] - a[j - 1];
					}
				}
				if(!v.size())
				{
					continue;
				}
				int l = 0,lst = i + 1;
				for(int j = v[0] + 1;j <= n;j++)
				{
					if(a[j] - a[j - 1] > d)
					{
						break;
					}
					while(lst < v[l] && a[j] - a[lst] > d)
					{
						lst++;
					}
					if(cntt[lst] + v[l] - lst == 1)
					{
						//cout << i << " " << j << endl;
						ans += (n - j + 1);
					}
					cntt[j] += cntt[lst] + v[l] - lst;
					if(v.size() > l + 1 && v[l + 1] == j)
					{
						if(cntt[j] > 1)
						{
							break;
						}
						l++;
						lst = v[l - 1] + 1;
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		if(C == 13 || C == 14)
		{
			int sum = 0,id;
			for(int i = 2;i <= n;i++)
			{
				sum += a[i] - a[i - 1];
				if(sum > d)
				{
					id = i - 1;
					break;
				}
			}
			int cnt = 0,cnt1 = 0;
			if(id == 2)
			{
				for(int i = 3;i <= n;i++)
				{
					if(a[i] - a[1] <= d)
					{
						cnt++;
					}
				}
				if(cnt == 1)
				{
					cout << n - id - 1 << "\n";
				}
				else
				{
					cout << 0 << "\n";
				}
			}
			else
			{
				for(int i = id + 1;i <= n;i++)
				{
					if(a[i] - a[id - 1] <= d && a[i] - a[id - 2] > d)
					{
						cnt++; 
					}
				}
				cnt *= (id - 2);
				for(int i = id + 1;i <= n;i++)
				{
					if(a[i] - a[id - 1] <= d)
					{
						cnt1++;
					}
				}
				if(cnt1 == 1)
				{
					cnt += n - id - 1;
				}
				cout << cnt << "\n";
			}
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			v.clear();
			for(int j = 1;j <= n;j++)
			{
				cntt[j] = 0;
			}
			int sum = 0;
			for(int j = i + 1;j <= n;j++)
			{
				sum += (a[j] - a[j - 1]);
				if(sum > d)
				{
					v.push_back(j - 1);
					sum = a[j] - a[j - 1];
				}
			}
			if(!v.size())
			{
				continue;
			}
			int l = 0,lst = i + 1;
			for(int j = v[0] + 1;j <= n;j++)
			{
				if(a[j] - a[j - 1] > d)
				{
					break;
				}
				while(lst < v[l] && a[j] - a[lst] > d)
				{
					lst++;
				}
				if(cntt[lst] + v[l] - lst == 1)
				{
					//cout << i << " " << j << endl;
					ans++;
				}
				cntt[j] += cntt[lst] + v[l] - lst;
				if(v.size() > l + 1 && v[l + 1] == j)
				{
					if(cntt[j] > 1)
					{
						break;
					}
					l++;
					lst = v[l - 1] + 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
