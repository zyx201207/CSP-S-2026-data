#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n, m;
int a[N];
int stk[N];
int ans[N];
int top=0;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	if(n<=500)
	{
		for(int k=1; k<=n; k++)
		{
			for(int i=k; i<=n; i++)
			{
				for(int j=1; j<=top; j++)
				{
					if(stk[j]==a[i])
					{
						top=j-1;
						break;
					}
				}
				stk[++top]=a[i];
			}
			for(int i=1; i<=top; i++) ans[stk[i]]++;
			top=0;
		}
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			ans[a[i]]=i;
		}
	}
	for(int i=1; i<=m; i++) cout << ans[i] << " ";
	return 0;
}
