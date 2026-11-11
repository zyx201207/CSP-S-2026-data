#include<bits/stdc++.h>
using namespace std;
long long m, n, a[500005];
int cnt[200005];
set<long long> st;
stack<long long> ss;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int sum = 1;
	while(sum <= n)
	{
		for(int i = sum; i <= n-m+1; i++)
		{
			if(st.count(a[i]))
			{
				while(ss.top() != a[i])
				{
					ss.pop();
				}
				ss.pop();
			}
			st.insert(a[i]);
		}
		
		for(int i = 1; i <= m; i++)
		{
			if(st.count(i)){
				int ssd = i;
				cnt[ssd] = cnt[ssd] + 1;
			}
		}
		sum++;	
	}
	for(int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
 } 
