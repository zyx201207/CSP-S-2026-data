#include<bits/stdc++.h>
using namespace std;


const int N = 5*1e5 + 10;
int in[N];


int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	//cout << N;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> in[i];
	}
	sort(in + 1, in + n + 1);
	int l = 1, r = 2;
	int ans = INT_MIN;
	//int pivot;
	long long sta = 0;
	sta += in[r] - in[l];
	while(r <= n)
	{
		//pivot = in[r];
		if(sta > m)
		{
			sta -= in[r] - in[l];
			l ++;
			continue;
		}
		if(sta <= m)
		{
			r += 1;
			sta += (in[r] - in[r - 1]) * (r - l); 
			ans = max(r - l, ans);
		}
	}
	cout << ans;
}
