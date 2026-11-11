#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,m;
const int N = 5e5 + 9;
int a[N];
int ans;
int b[N];

int main()
{
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++)
	{
		vector <int> nums;
		for(int j=i;j<=n;j++)
		{
			int l = nums.size();
			for(int k = 0;k < l;k++)
			{
				if(a[j] == nums[k])
				{
					int p = l-1;
					while(nums[p] != nums[k])
					{
						nums.pop_back();
						p--;
					} 
					nums.pop_back();
					break;
				}
			}
			nums.push_back(a[j]);
		}
		int l = nums.size();
		for(int i=0;i<l;i++) b[nums[i]]++;
	}
	for(int i=1;i<=m;i++) cout << b[i] << " ";
	return 0;
}
