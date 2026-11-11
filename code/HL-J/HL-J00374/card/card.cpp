#include<bits/stdc++.h>
using namespace std;
int n, m, a[545454], cnt[343434];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		vector<int> bs(m + 10);
		stack<int> v;
		for(int j = i; j < n; j++)
		{
			if(bs[a[j]])
			{
				while(v.size())
				{
					if(v.top() == a[j])
						break;
					bs[v.top()]--;
					v.pop();
				}
			}
			else
			{
				v.push(a[j]);
				bs[a[j]]++;
			}
		} 
		while(v.size())
		{
			cnt[v.top()]++;
			v.pop();
		}
	}
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	return 0;
	//Avada Kedavra
	//Ich brauche AK
}
