#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		ll sum=0;
		for(int j=i-1;j>0;j--)
		{
			if(sum+(a[i]-a[j])<=m)
			{
				sum+=(a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
