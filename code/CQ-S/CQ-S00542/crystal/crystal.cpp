#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,s1[N],s2[N],ans;
pair<int,int>b[N];
map<int,int>mp;
bool check(int l,int r)
{
	int oo=0;
	int ss1=s1[r-1]-s1[l-1],ss2=s2[r-1]-s2[l-1];
	if(b[r].first*ss2-ss1<=m)return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>n>>m;
	for(int i=1,x;i<=n;i++)cin>>x,mp[x]++;
	for(auto tt:mp)b[++cnt]=tt;
	for(int i=1;i<=cnt;i++)
	{
		s1[i]=s1[i-1]+b[i].first*b[i].second;
		s2[i]=s2[i-1]+b[i].second;
	}
	for(int i=1;i<=cnt;i++)
	{
		int l=1,r=i-1,as=i,now=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))as=mid,r=mid-1;
			else l=mid+1;
		}
		now=s2[i]-s2[as-1];
		if(as>1)
		{
			int ss1=s1[i-1]-s1[as-1],ss2=s2[i-1]-s2[as-1];
			int mm=m-(b[i].first*ss2-ss1),kk=b[i].first-b[as-1].first;
			if(kk)now+=(mm/kk);
		}
		ans=max(ans,now);
	}
	cout<<ans<<'\n';
	return 0;
}
