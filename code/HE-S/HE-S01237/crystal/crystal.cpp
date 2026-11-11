#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n,m;
int engy[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> engy[i];
	}
	sort(engy + 1,engy + n + 1,greater<int>());
	
	int ans = 1;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		int a = m;
		ans = 1;
		for(int j = i + 1;j <= n;j++)
		{
			if(a - (engy[i] - engy[j]) >= 0) ans++;
		}
		sum = max(sum,ans);
	}
	cout << sum;
	
	return 0;
}

