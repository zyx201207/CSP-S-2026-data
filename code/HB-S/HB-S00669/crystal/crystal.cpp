#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5+5;

int n;
ll m;

ll a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	//s[1]=0;
	
	//for(int i=2;i<=n;i++)
	//	s[i]=s[i-1]+(a[i]-a[i-1])*1ll*(i-1);
	
	int ans=1;
	
	int l=1;
//	ll tmp=0;
	
	__int128 sum=0;
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-l);
		while(l<i&&sum>m) sum-=(a[i]-a[l]),l++;
		
//		if(l==1&&s[i]>m) l++,tmp+=(a[i]-a[1]);
//		while(l<i&&s[i]-(a[i]-a[l-1])-tmp>m) l++,tmp+=(a[i]-a[l]);
		ans=max(ans,i-l+1);
	}
	
	cout<<ans;
	return 0;
}
