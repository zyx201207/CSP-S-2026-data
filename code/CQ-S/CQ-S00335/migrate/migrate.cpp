#include<bits/stdc++.h>
using namespace std;

int c,t,d,n,x[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				int w = j-i;
				if(w==3 && x[j]-x[i] > d)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
 } 
