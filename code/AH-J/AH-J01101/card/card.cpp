#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005

int n,m;
int arr[MAXN];
int ans[MAXN] = {0};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	stack<int> v;
	int fs[MAXN];
	for(int i = 1; i <= n; i++)
	{
		memset( fs, 0, sizeof(fs) );
		for(int j = i; j <= n; j++)
		{
			
		    if(fs[ arr[j] ] == 1)
			{
				while(!v.empty() && v.top() != arr[j])
				{
					fs[v.top()] = 0;
					v.pop();
				}
			}
			else
			{
				v.push(arr[j]);
				fs[arr[j]] = 1;
			}
		}
		while(!v.empty())
		{
			ans[v.top()]++;
			v.pop();
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}
