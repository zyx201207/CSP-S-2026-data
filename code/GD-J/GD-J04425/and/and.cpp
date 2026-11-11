#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,k[N][32],ans;
bool flag[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		int cnt=0;
		while(a)
		{
			k[i-1][cnt++]=a%2;
			a/=2;
		}
	}
	for(int i=1;i<=n;i++) flag[i]=true;
	for(int i=30;i>=1;i--)
	{
		int sum=0;
		for(int t=1;t<=n;t++)
			if(k[t-1][i-1] && flag[t]) sum++;
		if(sum<m) continue;
		for(int t=1;t<=n;t++)
			flag[t] &= k[t-1][i-1];
		ans=ans+(1<<(i-1));
	}
	cout<<ans<<endl;
	return 0; 
}
