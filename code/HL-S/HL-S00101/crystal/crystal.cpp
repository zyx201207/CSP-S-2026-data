#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int ans = -1;
	for(int i = 1;i <= n;i++) //jizhun
	{
		int count_m = 0;
		int count_num = 0;
		for(int j = i-1;j>=0;j--)
		{
			count_m+=a[i]-a[j];
			if(count_m<=m)
			{
				count_num++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans,count_num);
	}
	cout<<ans+1;
	return 0;
}
