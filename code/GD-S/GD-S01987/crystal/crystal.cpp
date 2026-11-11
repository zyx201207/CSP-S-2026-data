#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
ll cnt[N];
bool cmp(ll a,ll b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cnt[1]=0;
	for(int i=2;i<=n;i++)
	{
		int j=i-1;
		cnt[i]=cnt[j]+(a[i]-a[j])*j;
	}

	int ans=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-ans;j>=1;j--)
		{
			ll k=cnt[i]-cnt[j]-(a[i]-a[j])*(j-1);
			if(k<=m)
			{
				ans=max(ans,i-j+1);
			}
			else break;
		}
	}
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

