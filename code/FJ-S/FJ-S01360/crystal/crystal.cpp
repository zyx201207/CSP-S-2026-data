#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long num[500005];
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> m;
 	for(int i = 1;i<=n;i++)
 	{
 		cin >> num[i];
	}
	sort(num+1,num+n+1);
	long long l=1,r=1;
	long long ans=0;
	long long cur=0;
	while(l<=r&&r<=n)
	{
		cur+=(num[r]-num[r-1])*(r-l);
		if(cur<=m)
		{
			ans=max(ans,r-l+1);
		}
		else
		{
			while(cur>m)
			{
				cur-=num[r]-num[l];
				l++;
			}
		}
		r++;
	}
	cout << ans;
 	return 0;
}

