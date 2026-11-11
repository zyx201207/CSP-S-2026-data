#include<bits/stdc++.h>
using namespace std;
int N[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>N[i];
		N[i] += N[i - 1];
	}
	int ans = 0;
	int l1 = 0,l2 = 0;
	int cnt1,cnt2;
	for(int i1 = 1;i1 <= n;i1++)
	{
		for(int j1 = 1;j1 <= n;j1++)
		{
			cnt1 = N[j1] - N[i1];
			for(int i2 = 1;i2 <= n;i2++)
			{
				for(int j2 = 1;j2 <= n;j2++)
				{
					cnt2 = N[j2] - N[j1];
					if(cnt1 == cnt2) ans++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
