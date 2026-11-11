#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
int ans;
long long w[N];
long long sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	sort(w+1,w+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+w[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int num=0;
		int last;
		while(1)
		{
			int mid=l+((r-l)>>1);
			if(last==mid)break;
			int cnt=i-mid;
			if((w[i]*cnt-(sum[i-1]-sum[mid-1]))>m)l=mid;
			else
			{
				num=max(num,cnt);
				r=mid;
			}
			last=mid;
		}
		ans=max(ans,num);
	}
	cout<<ans+1;
	return 0;
}
